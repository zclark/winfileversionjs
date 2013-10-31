#ifndef UNICODE
#define UNICODE
#endif

#pragma comment(lib, "node")
#pragma comment(lib, "Version")

#include <node.h>
#include <v8.h>
#include <Windows.h>
#include <string>

using namespace node;
using namespace v8;

Handle<Value> GetFileVersion(const Arguments& args) {
	HandleScope scope;
  const unsigned returnSize = 5;

	Local<Function> callback = Local<Function>::Cast(args[1]);

	v8::String::Utf8Value param1(args[0]->ToString());
	std::string s = std::string(*param1);
	std::wstring stemp = std::wstring(s.begin(), s.end());
	LPCWSTR filePath = stemp.c_str();

	DWORD versionHandle = NULL;
	UINT size = 0;
	LPBYTE lpBuffer = NULL;
	DWORD versionSize = GetFileVersionInfoSize(filePath, &versionHandle);

	if (versionSize != NULL) {
		LPSTR versionData = new char[versionSize];
		if (GetFileVersionInfo(filePath, versionHandle, versionSize, versionData)) {
			if (VerQueryValue(versionData, L"\\", (VOID FAR* FAR*)&lpBuffer, &size)) {
				if (size) {
					VS_FIXEDFILEINFO *versionInfo = (VS_FIXEDFILEINFO*)lpBuffer;

					if (versionInfo->dwSignature == 0xfeef04bd) {
						int major = HIWORD(versionInfo->dwFileVersionMS);
						int minor = LOWORD(versionInfo->dwFileVersionMS);
						int buildMajor = HIWORD(versionInfo->dwFileVersionLS);
						int buildMinor = LOWORD(versionInfo->dwFileVersionLS);

						Local<Value> returnValue[returnSize] = {
							Local<Value>::New(Null()),
							Local<Value>::New(Integer::New(major)),
							Local<Value>::New(Integer::New(minor)),
							Local<Value>::New(Integer::New(buildMajor)),
							Local<Value>::New(Integer::New(buildMinor))
						};

						callback->Call(Context::GetCurrent()->Global(), returnSize, returnValue);
					}
				}
			}
		}
	} else {
		Local<Value> returnValue[returnSize] = {
			Local<Value>::New(String::New("No file version info could be found")),
			Local<Value>::New(Null()),
			Local<Value>::New(Null()),
			Local<Value>::New(Null()),
			Local<Value>::New(Null())
		};

		callback->Call(Context::GetCurrent()->Global(), returnSize, returnValue);
	}

	return Undefined();
}

void RegisterModule(Handle<Object> target) {
	target->Set(String::NewSymbol("getFileVersion"),
		FunctionTemplate::New(GetFileVersion)->GetFunction());
}

NODE_MODULE(winFileVersion, RegisterModule);
