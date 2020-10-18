#pragma once
#include <d3d11.h>

class GraphicsEngine
{
public:
	bool Initialize();
	bool Release();
	static GraphicsEngine* Get();
private:
	ID3D11Device* d3d_device;
	D3D_FEATURE_LEVEL d3d_feature_lvl;
	ID3D11DeviceContext* d3d_device_context;
};

