#pragma once
#include <Windows.h>

class Window
{
public:
	bool Initialize();
	bool Broadcast();
	bool Release();
	bool IsRunning() const;
	// our custom Window actions during:
	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroy() = 0;

protected:
	// LRESULT CALLBACK WindowProc(HWND handle, UINT uMsg, WPARAM wParam, LPARAM lParam );
	// this guy has to be global- otherwise Windows.h wouldn't be able to call it!
	HWND handle;
	bool is_running = false;
};

