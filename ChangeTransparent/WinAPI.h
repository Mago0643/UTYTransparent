#include <windows.h>
#include <tchar.h>

class WinAPI
{
public:
	static TCHAR* GetClassNameFromWindow(HWND window);
	// returns -1 if there was an error.
	// returns 0 if the window is not long type.
	// return 1 if the window is long type.
	static int IsLongWindow(HWND window);
	static bool SetWindowColorAlpha(HWND window, COLORREF col, byte alpha);
private:

};