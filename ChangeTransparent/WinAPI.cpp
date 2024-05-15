#include "WinAPI.h"
#include <iostream>
#include <stdio.h>

TCHAR* WinAPI::GetClassNameFromWindow(HWND window)
{
	TCHAR className[MAX_PATH];
	TCHAR ok[MAX_PATH];
	GetClassName(window, className, _countof(ok));
	return className;
}

int WinAPI::IsLongWindow(HWND window)
{
	// https://stackoverflow.com/questions/44267625/invalid-parameter-error-on-setlayeredwindowattributes
	SetLastError(0);
	int winFlags = (int)GetWindowLongPtr(window, GWL_EXSTYLE);
	if (winFlags == 0)
	{
		printf("\nWinAPI Error: Failed to Get Window Long. (%d)", GetLastError());
		return -1;
	}
	bool a = (winFlags & WS_EX_LAYERED) != 0;
	return a ? 1 : 0;
}

bool WinAPI::SetWindowColorAlpha(HWND window, COLORREF col, byte alpha)
{
	int check = IsLongWindow(window);
	switch (check)
	{
		case 0:
		{
			int winFlags = (int)GetWindowLongPtr(window, GWL_EXSTYLE);
			winFlags |= WS_EX_LAYERED;
			SetLastError(0);
			if (SetWindowLongPtr(window, GWL_EXSTYLE, winFlags) == 0)
			{
				if (GetLastError() != 0)
				{
					printf("\nWinAPI Error: Failed to Set Window Long. (%d)", GetLastError());
					return false;
				}
			}
		}
		case -1:
		{
			printf("\nWinAPI Error: Failed to Check Window Long. (%d)", GetLastError());
			return false;
			break;
		}
	}
	return SetLayeredWindowAttributes(window, col, alpha, LWA_COLORKEY);
}