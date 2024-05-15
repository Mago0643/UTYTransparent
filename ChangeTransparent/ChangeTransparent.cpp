// made with - my bad coding skills

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <winuser.h>
#include "WinAPI.h"

// #define GET_CLASS_NAME

void PrintLastError()
{
    printf("\n\nERROR: %ld", GetLastError());
}

int main()
{
    system("mode con cols=100 lines=20 | title ChangeTransparent");
    //std::cout << "Hello World!\n";
    std::cout << "Finding Undertale Yellow...";
    HWND UTY = FindWindowA("YYGameMakerYY", "Undertale Yellow");
    if (UTY == NULL)
    {
        // std::cout << "\nError: " + GetLastError();
        PrintLastError();
        std::cout << "\n\nPlease Check Undertale Yellow is Running.\n";
        return -1;
    }

#ifdef GET_CLASS_NAME
    _tprintf(_T("\nClass Name is: %s\n"), WinAPI::GetClassNameFromWindow(UTY));
#else
    std::cout << "\nFound it!";
    int r, g, b;
    printf("\nPlease Enter RGB Values to make it transparent. (Example: 255 255 255)\nIf you want to disable this, type anything.\n> ");
    scanf_s("%d %d %d", &r, &g, &b);
    std::cout << "\nSetting Window's Attributes...";
    bool result = WinAPI::SetWindowColorAlpha(UTY, RGB(r, g, b), 0);
    if (result)
    {
        std::cout << "\n\nDone.\nPlease Remember to Close The Game with ALT + F4 or Task Manager.\n\n";
    }
    else
    {
        PrintLastError();
        return -1;
    }
#endif
    return 0;
}