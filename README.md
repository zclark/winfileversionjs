winfileversionjs
==========
#### Node.js addon for reading windows file version information

Installation
---------------
If you have Visual Studio 2010 Express installed you can probably just do this
```bash
npm install winfileversion
```

But if you're like me and have 2012 instead and don't want to waste disk space on old junk, use this flag:
```bash
npm install winfileversion --msvs_version=2012
```

Usage
---------------
```js
  var winFileVersion = require('./path/to/winFileVersion.node');

  winFileVersion.getFileVersion('path/to/file', 
    function (err, major, minor, buildMajor, buildMinor) {
      // do stuff
    });
```

License
---------------
The MIT License (MIT)

Copyright (c) 2013 Zach Clark <zachmclark@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.