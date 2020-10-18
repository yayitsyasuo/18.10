#include "WinApp.h"

void WinApp::onCreate()
{
	//Window::onCreate();
	GraphicsEngine::Get()->Initialize();
}

void WinApp::onUpdate() 
{
}

void WinApp::onDestroy()
{
	is_running = false;
	GraphicsEngine::Get()->Release();
	//Window::onDestroy();
}
