#ifndef APPLICATION_H
#define APPLICATION_H

#include <cstdint>


#include "Platform/Generic/Window.h"


class Application
{
public:
	static Window* MakeWindow(int32_t x, int32_t y, int32_t w, int32_t h, wchar_t* name);
	static void UpdatePlatform();
	static void MainLoop();
	static bool running;
	static void Init();
	//This has to be platform specific, since Windows is kinda weird here and needs dummy HWND and DC to get OpenGL to work properly.
	static void InitGL();
	//Temporary name, might and most likely will change.
	static void CreateGLDevice();
	//Debug function to check if GL is loaded corectly.
	static void DrawGLTriangle();
	//pointer to main application window.
	static Window* mainWindow;
};

#endif