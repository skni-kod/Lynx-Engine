// TODO: This file is called LynxWindow just because Window would collide with the Xlib Window type. Resolve this using namespaces??
// TODO: Wrap this into a class

#ifndef LYNX_ENGINE_LYNXWINDOW_H
#define LYNX_ENGINE_LYNXWINDOW_H

#include "Event.h"

// TODO: typedef this for C compatibility?
struct LynxWindow;

// TODO: document these
LynxWindow* createWindow();
bool destroyWindow(LynxWindow*);
bool pollEvent(LynxWindow*, Event*);
bool waitEvent(LynxWindow*, Event*);
void close(LynxWindow*);
void requestFocus(LynxWindow*);
void setSize(LynxWindow*, uint32_t, uint32_t);
void getSize(LynxWindow*, uint32_t*, uint32_t*);
void setPosition(LynxWindow*, int32_t, int32_t);
void getPosition(LynxWindow*, int32_t*, int32_t*);

#endif //LYNX_ENGINE_LYNXWINDOW_H
