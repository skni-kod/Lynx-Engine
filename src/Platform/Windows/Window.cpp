#include "Platform/Windows/WindowData.h"
#include "Platform/Generic/Window.h"


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


const TCHAR WindowData::AppWindowClass[] = L"LynxWindow";

void Window::Reshape(int32_t x, int32_t y, int32_t width, int32_t height)
{
	//TODO: Add Reshape() to Win32
	throw;
}

void Window::SetPosition(int32_t x, int32_t y)
{
	SetWindowPos(windowData.hwnd, nullptr, x, y, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOZORDER);
}

void Window::Minimize()
{
	ShowWindow(windowData.hwnd, SW_MINIMIZE);
}

void Window::Maximize()
{
	ShowWindow(windowData.hwnd, SW_MAXIMIZE);
}

void Window::Restore()
{
	ShowWindow(windowData.hwnd, SW_RESTORE);
}

void Window::Show()
{
	ShowWindow(windowData.hwnd, SW_SHOW);
}

void Window::Hide()
{
	ShowWindow(windowData.hwnd, SW_HIDE);
}

void Window::Focus()
{
	//TODO: Add Focus() to Win32
	throw;
}
