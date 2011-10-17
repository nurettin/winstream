
Türkçe
======

Açiklama
--------
	
	Windows XP isletim sisteminde Code::Blocks ile ders vermeyi kolaylastirmak için yazilmistir. Windows konsolu için std::cout nesnesinin streambuf niteligini WriteConsole kullanacak sekilde modifiye eder.

Kullanim
--------
	
	winstream.cpp dosyasini projenize kopyalamaniz yeterli. 

Notlar
------

	winstream.cpp'nin link zamani std::cout'un ayarlarini yapan libstdc++ baglama zamanindan once olmali. Bunu yapmanin deterministik bir yontemi yok, simdilik windows/mingw/gcc'den gozlemlenmis davranis std::cout ayarlamasinin winstream'den önce olmasi. 


English
=======

Explanation
-----------

	Written to simplify teaching with Code::Blocks in class. Alters the streambuf of std::cout to use WriteConsole on Windows console. 

Usage
-----

	Just copy the winstream.cpp file to your project.

Notes
-----
	
	winstream.cpp must be linked after libstdc++ which initializes std::cout. There is no deterministic way of doing this, but the observed behavior on windows/mingw/gcc is that std::cout initializes first. 

