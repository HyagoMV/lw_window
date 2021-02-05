#include <windows.h>


HWND _init(LPCWSTR title, int width, int height);

typedef struct {
	int width;
	int height;
	LPCWSTR title;
	HWND handle;
} Window;

Window* createWindow(LPCWSTR title, int width, int height) {
	Window* window = (Window*) malloc(sizeof(Window));
	

	window->title = title;
	window->width = width;
	window->height = height;

	window->handle = _init(title, width, height);
	
	return window;
};

void destroyWindow(Window* window) {
	free(window);
}

void showWindow(Window* window) {
	ShowWindow(window->handle, SW_SHOWNA);
}

// ----------

static LRESULT CALLBACK windowProc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam) {
	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

HWND _init(LPCWSTR title, int width, int height) {
	WNDCLASSEXW wc;

	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)windowProc;
	wc.hInstance = GetModuleHandleW(NULL);
	wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wc.lpszClassName = L"TEST";

	RegisterClassExW(&wc);

	DWORD		exStyle = 262144;
	LPCWSTR		className = L"TEST";
	LPCWSTR		windowName = title;
	DWORD		style = 114229248;
	int			x = 0;
	int			y = 0;
	HWND		parent = NULL;
	HMENU		menu = NULL;
	HINSTANCE	instance = GetModuleHandleW(NULL);
	LPVOID		param = NULL;

	return  CreateWindowExW(
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
}