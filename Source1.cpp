#include <windows.h>
#include <iostream>

static LRESULT CALLBACK windowProc(
	HWND hWnd, 
	UINT uMsg,
	WPARAM wParam, 
	LPARAM lParam) {
	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

void main2() {
	WNDCLASSEXW wc;

	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize			= sizeof(wc);
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc		= (WNDPROC) windowProc;
	wc.hInstance		= GetModuleHandleW(NULL);
	wc.hCursor			= LoadCursorW(NULL, IDC_ARROW);
	wc.lpszClassName	= L"TEST";

	RegisterClassExW(&wc);
	
	



	DWORD		exStyle		= 262144;
	LPCWSTR		className	= L"TEST";
	LPCWSTR		windowName	= L"Title";
	DWORD		style		= 114229248;
	int			x			= 0;
	int			y			= 0;
	int			width		= 400;
	int			height		= 300;
	HWND		parent		= NULL;
	HMENU		menu		= NULL;
	HINSTANCE	instance	= GetModuleHandleW(NULL);
	LPVOID		param		= NULL;

	HWND wnd = CreateWindowExW(
		exStyle,
		className,
		windowName,
		style,
		x, y,
		width, height,
		parent,
		menu, 
		instance,
		param
	);

	//SetPropW(wnd, L"TEST", window);

	ShowWindow(wnd, SW_SHOWNA);

}