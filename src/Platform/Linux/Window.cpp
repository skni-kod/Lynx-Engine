#include "Config.h"

#if defined(LYNX_PLATFORM_LINUX)

#include "Platform/C/LynxWindow.h"
#include <X11/Xlib.h>

struct LynxWindow {
    Display *d;
    Window w;
    XEvent xevent;
    int s;
};

LynxWindow* createWindow() {
    auto win = new LynxWindow;

    win -> d = XOpenDisplay(nullptr);
    if (win -> d == nullptr)
        return nullptr;

    win -> s = DefaultScreen(win -> d);
    win -> w = XCreateSimpleWindow(win -> d, RootWindow( win -> d, win -> s), 10, 10, 100, 100, 1,
                            BlackPixel(win -> d, win -> s), WhitePixel(win -> d, win -> s));

    XSelectInput(win -> d, win -> w, ExposureMask | KeyPressMask);
    XMapWindow(win -> d, win -> w);

    return win;
}

bool destroyWindow(LynxWindow* win) {
    XDestroyWindow(win -> d, win -> w);
    XCloseDisplay(win -> d);
    return true;
}

bool pollEvent(LynxWindow *win, Event *e) {
    XNextEvent(win -> d, &win -> xevent); // oops this blocks
    return true;
}

bool waitEvent(LynxWindow *win, Event *e) {
    XNextEvent(win -> d, &win -> xevent);
    return true;
}

void close(LynxWindow*) {

}

void requestFocus(LynxWindow*) {

}

void setSize(LynxWindow *win, uint32_t width, uint32_t height) {
    XResizeWindow(win -> d, win -> w, width, height);
}

void getSize(LynxWindow*, uint32_t*, uint32_t*) {

}

void setPosition(LynxWindow *win, int32_t x, int32_t y) {
    XMoveWindow(win -> d, win -> w, x, y);
}

void getPosition(LynxWindow*, int32_t*, int32_t*) {

}

// Platform specific functions

void setBorderWidth(LynxWindow* win, uint32_t width) {
    XSetWindowBorderWidth(win -> d, win -> w, width);
}

#endif // LYNX_PLATFORM_LINUX
