#include "window.h"


int main() { 
	Window* window = createWindow(L"Title", 400, 300);

	showWindow(window);
	destroyWindow(window);
	return 0; 
}