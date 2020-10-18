#include "WinApp.h"

int main() {
	
	WinApp WinApp;
	WinApp.Initialize();

	while ( WinApp.IsRunning() ) {
		WinApp.Broadcast();
	}

	return 0;
}