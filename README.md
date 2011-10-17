
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
