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
