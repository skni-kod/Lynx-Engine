// TODO: Wrap this into a class

#ifndef LYNX_ENGINE_WINDOW_H
#define LYNX_ENGINE_WINDOW_H

#include "Event.h"

struct Window;

// TODO: document these
Window* createWindow();
bool destroyWindow(Window *window);
bool pollEvent(Window *window, Event *event);
bool waitEvent(Window *window, Event *event);
void close(Window *window);
void requestFocus(Window *window);
void setSize(Window *window, uint32_t width, uint32_t height);
void getSize(Window *window, uint32_t *width, uint32_t *height);
void setPosition(Window *window, int32_t x, int32_t y);
void getPosition(Window *window, int32_t *x, int32_t *y);

#endif //LYNX_ENGINE_WINDOW_H
