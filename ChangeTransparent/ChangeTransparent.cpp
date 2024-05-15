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
    /*SetLastError(0);
    int winFlags = (int)GetWindowLongPtr(UTY, GWL_EXSTYLE);
    if (winFlags == 0)
    {
        PrintLastError();
        return -1;
    }
    if ((winFlags & WS_EX_LAYERED) == 0)
    {
        std::cout << "\nSetting Window to Long Type.";

        winFlags |= WS_EX_LAYERED;
        SetLastError(0);
        if (SetWindowLongPtr(UTY, GWL_EXSTYLE, winFlags) == 0)
        {
            DWORD error = GetLastError();
            if (error != 0)
            {
                PrintLastError();
                return -1;
            }
        }
    }*/
    int r, g, b;
    printf("\nPlease Enter RGB Values to make it transparent. (Example: 255 255 255)\nIf you want to disable this, type anything.\n> ");
    scanf_s("%d %d %d", &r, &g, &b);
    std::cout << "\nSetting Window's Attributes...";
    // bool result = SetLayeredWindowAttributes(UTY, RGB(r, g, b), 0, LWA_COLORKEY);
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

/* color palette:
    dark ruins path color: 72, 31, 72
    dark ruins floor color: 97, 44, 97
    dark ruins wall brick color: 63, 28, 63 or 83, 37, 83
    dark ruins wall color: 97, 44, 97
    gunhat's hat color: 135, 54, 0
    gunhat's outline color (or hat): 61, 18, 14
    gunhat's hair color: 104, 41, 0
    gunhat's skin color: 255, 232, 172
    gunhat's bandana color (or pants): 19, 42, 99
    yellow: 255, 216, 0
*/