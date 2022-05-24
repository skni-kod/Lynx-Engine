#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

struct Win32WindowData
{
	HWND hwnd;
	static const TCHAR AppWindowClass[];
};

typedef Win32WindowData WindowData;