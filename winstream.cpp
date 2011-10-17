/*
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
*/

/*
    Project: WinStream
*/

#ifdef WIN32

#include <streambuf>
#include <iostream>
#include <stdexcept>
#include <windows.h>

struct WinApiStreambuf: std::streambuf
{
    HANDLE out_handle;

    WinApiStreambuf()
    {
        out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    std::streamsize xsputn(char const* msg, std::streamsize length)
    {
        DWORD t;
        WriteConsole(out_handle, msg, length, &t, 0);
        return length;
    }
};

namespace
{

struct Console
{
    std::streambuf* cout_streambuf;

    Console()
    {
        SetConsoleOutputCP(CP_UTF8);
        WinApiStreambuf* win_streambuf= new WinApiStreambuf;
        cout_streambuf= std::cout.rdbuf(win_streambuf);

        typedef BOOL (WINAPI *SetConsoleFont_t)(HANDLE, DWORD);
        typedef DWORD (WINAPI *GetNumberOfConsoleFonts_t)();

        HMODULE hm = GetModuleHandle("kernel32.dll");

        SetConsoleFont_t SetConsoleFont= (SetConsoleFont_t)GetProcAddress(hm, "SetConsoleFont");
        GetNumberOfConsoleFonts_t GetNumberOfConsoleFonts= (GetNumberOfConsoleFonts_t)GetProcAddress(hm, "GetNumberOfConsoleFonts");

        int n_console_fonts= GetNumberOfConsoleFonts();
        int console_font_index=
            n_console_fonts== 10 ? 10 :
            n_console_fonts> 10 ? 11 :
            throw std::runtime_error("Unable to find assumed console font");

        SetConsoleFont(win_streambuf-> out_handle, console_font_index);
    }

    ~Console()
    {
        delete std::cout.rdbuf(cout_streambuf);
    }
} console_init;

}

#endif
