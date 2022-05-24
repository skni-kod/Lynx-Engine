#include <cstdint>
#include <cstdio>

#include "Platform/Generic/Window.h"
#include "Platform/Generic/Application.h"


//TODO: Pass commandline params.
int32_t GenericMain()
{
	printf("Welcome from generic main!\n");

	Application::Init();
	Application::InitGL();
	
	Application::mainWindow = Application::MakeWindow(0, 0, 1280, 720, L"LYNX");
	Application::CreateGLDevice();

	Application::mainWindow->Show();

	Application::MainLoop();

	return 0;
}

