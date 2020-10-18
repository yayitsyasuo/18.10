#pragma once
#include "Window.h"
#include "GraphicsEngine.h"

class WinApp : public Window
{
public:
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
};

