#include "Window.h"

//idk about this one
//Window* window = nullptr;

LRESULT CALLBACK WindowProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// this guy is global that's why you can't understand it yet
	// u can't use any not global member here

	switch (msg) {
	case WM_CREATE:
	{
		auto* const parameter = reinterpret_cast<LPCREATESTRUCT>(lParam);
		Window* const window = reinterpret_cast<Window* const>(parameter->lpCreateParams);

		SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));

		window->onCreate();
		break;
	}
	case WM_DESTROY:
	{
		auto* const window = reinterpret_cast<Window* const>(GetWindowLongPtr(handle, GWLP_USERDATA));

		window->onDestroy();
		PostQuitMessage(69);
		break;
	}
	default:
		return DefWindowProc(handle, msg, wParam, lParam);
	}
	return NULL;
}


bool Window::Initialize()
{
	// Register the Window Class
	WNDCLASSEX wc;
	wc.cbSize = sizeof(wc);
	wc.style = NULL;
	wc.lpfnWndProc = WindowProc; // the big guy, (LRESULT*)() - function pointer, MUST HAVE AN ACCESS!
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = NULL;
	wc.hIcon = LoadIconA(NULL, IDI_SHIELD);
	wc.hCursor = LoadCursorA(NULL, IDC_CROSS);
	wc.hbrBackground = HBRUSH(COLOR_ACTIVECAPTION);
	wc.lpszMenuName = "Du kommst schon klar";
	wc.lpszClassName = "WindowClass";
	wc.hIconSm = LoadIconA(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
		return false;
	


	// Create the Window Class - kein Struct, sondern a function 
	// returns a Handle to the new Window Class
	handle=	CreateWindowEx(
			WS_EX_OVERLAPPEDWINDOW,
			"WindowClass", "Battlefield 1944",
			WS_TILEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			1024, 768,
			NULL, NULL, NULL, this); // extra data for the Window class
									 // you'll need it once you step into the global space
	
	if (handle == NULL)
		return false;

	// Show the goddamn Window
	ShowWindow(handle, SW_SHOW);
	UpdateWindow(handle); //unnecessary

	is_running = true;
	
	return true;
}

bool Window::Broadcast()
{
	MSG msg;
	while (PeekMessage(&msg, handle, NULL, NULL, PM_REMOVE) > 0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	onUpdate();

	Sleep(0);

	return true;
}

bool Window::Release()
{
	is_running = false;
	if (!DestroyWindow(handle))
		return false;

	return true;
}

bool Window::IsRunning() const
{
	return is_running;
}
