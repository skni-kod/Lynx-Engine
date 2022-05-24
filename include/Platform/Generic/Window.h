#ifndef WINDOW_H
#define WINDOW_H

//TODO Create proper type includes, so we have complete control over data types and sizes.
#include <cstdint>

#ifdef WIN32
#include "../Windows/WindowData.h"
#endif

//TODO: Remember to make all methods here abstract and virtual, not a single one should work with platform specific things

class Window
{
private:

//TODO: Sort methods and fields into more logical code layout.
public:

	/**
	* Changes position and size of window.
	* @param x - new x coordinate of window position.
	* @param y - new y coordinate of window position.
	* @param width - new width of the window size.
	* @param height - new height of the window size.
	*/
	void Reshape(int32_t x, int32_t y, int32_t width, int32_t height);

	/**
	* Sets windows to position (x,y) at platform screen.
	* @param x - new x coordinate of window position.
	* @param y - new y coordinate of window position.
	*/
	void SetPosition(int32_t x, int32_t y);

	/**
	* Minimize window.
	*/
	void Minimize();

	/**
	* Maximize window.
	*/
	void Maximize();

	/**
	* Restore window.
	*/
	void Restore();

	/**
	* Show window.
	*/
	void Show();

	/**
	* Hide window.
	*/
	void Hide();

	/**
	* Bring window to front and focus cursor on it.
	*/
	void Focus();

	/**
	* Structure containing all window data.
	*/
	WindowData windowData;
};

#endif
