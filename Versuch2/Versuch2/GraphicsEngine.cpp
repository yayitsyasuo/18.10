#pragma comment(lib,"d3d11.lib")
#include "GraphicsEngine.h"
#include <d3d11.h>
bool GraphicsEngine::Initialize()
{
	D3D_DRIVER_TYPE driver_types[] = {
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT driver_types_num = ARRAYSIZE(driver_types);

	D3D_FEATURE_LEVEL feature_levels[] =
	{
		D3D_FEATURE_LEVEL_11_0
	};
	UINT feature_levels_num = ARRAYSIZE(feature_levels);

	HRESULT result;
	for (UINT driver_types_index = 0; driver_types_index < driver_types_num; ) {
			result =
				D3D11CreateDevice(NULL,
				driver_types[driver_types_index],
				NULL, NULL, feature_levels, feature_levels_num, D3D11_SDK_VERSION,
				&d3d_device, &d3d_feature_lvl, &d3d_device_context);

			if (SUCCEEDED(result)) {
				break;
				driver_types_index++;
			}

	}
	if (FAILED(result))
		return false;
	return true;
}

bool GraphicsEngine::Release()
{
	d3d_device->Release();
	d3d_device_context->Release();
	return true;
}

GraphicsEngine * GraphicsEngine::Get()
{
	static GraphicsEngine graphics_engine;
	return &graphics_engine;
}
