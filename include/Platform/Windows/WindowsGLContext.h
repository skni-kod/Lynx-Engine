#ifndef WINDOWSGLCONTEXT_H
#define WINDOWSGLCONTEXT_H

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Platform/Windows/WindowsGLDefines.h"

//Consider changing HWND to WindowsWindow class or something in future
HGLRC InitWindowsGLContext(HWND hwnd, HINSTANCE& hInstance);
bool InitWindowsGLExtensions(HINSTANCE& hInstance);

#endif