Copyright (C) 2011 by Nurettin Onur TUĞCU (onur.tugcu@gmail.com)

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

Project: WinStream

Türkçe
======

Açıklama
--------

Windows XP işletim sisteminde Code::Blocks ile UTF-8 ortamında ders vermeyi kolaylaştırmak için yazılmıştır. Windows konsolu için std::cout nesnesinin streambuf niteliğini WriteConsole kullanacak şekilde modifiye eder.

Kullanım
--------

winstream.cpp dosyasını projenize kopyalamanız yeterli.

Notlar
------

winstream.cpp'nin link zamanı std::cout'un ayarlarını yapan libstdc++ baglama zamanından önce olmali. Bunu yapmanın deterministik bir yöntemi yok, şimdilik windows/mingw/gcc'den gözlemlenmiş davranış std::cout ayarlamasının winstream'den önce olması.


English
=======

Explanation
-----------

Written to simplify teaching with Code::Blocks in class in a UTF-8 environment. Alters the streambuf of std::cout to use WriteConsole on Windows console.

Usage
-----

Just copy the winstream.cpp file to your project.

Notes
-----

winstream.cpp must be linked after libstdc++ which initializes std::cout. There is no deterministic way of doing this, but the observed behavior on windows/mingw/gcc is that std::cout initializes first.
