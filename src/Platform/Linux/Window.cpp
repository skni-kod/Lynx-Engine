#include "Platform/C/Window.h"
#include "cstdio"


// Ugly hack to avoid type name collision (Window)
namespace X11 {
    #include <X11/Xlib.h>
    #undef _XPrivDisplay
    #define _XPrivDisplay X11::_XPrivDisplay
}


bool translateEvent(X11::XEvent *xe, Event *e) {
    switch(xe -> type) {
        case KeyPress:
            e -> type = Event::EventType::KeyPressed;
            e -> keyEvent = Event::KeyEvent{};
            printf("Key Pressed: %d\n", xe->xkey.keycode);
            return true;
        case KeyRelease:
            e -> type = Event::EventType::KeyReleased;
            e -> keyEvent = Event::KeyEvent{};
            printf("Key Released: %d\n", xe->xkey.keycode);
            return true;
    }
    return false;
}

struct Window {
    X11::Display *d;
    X11::Window w;
    X11::XEvent xevent;
    int s;
};

Window* createWindow() {
    auto win = new Window;

    win -> d = X11::XOpenDisplay(nullptr);
    if (win -> d == nullptr)
        return nullptr;

    win -> s = DefaultScreen(win -> d);
    win -> w = XCreateSimpleWindow(win -> d, RootWindow( win -> d, win -> s), 10, 10, 100, 100, 1,
                            BlackPixel(win -> d, win -> s), WhitePixel(win -> d, win -> s));

    XSelectInput(win -> d, win -> w, ExposureMask | KeyPressMask);
    XMapWindow(win -> d, win -> w);

    return win;
}

bool destroyWindow(Window* win) {
    XDestroyWindow(win -> d, win -> w);
    XCloseDisplay(win -> d);
    return true;
}

bool pollEvent(Window *win, Event *e) {
    XNextEvent(win -> d, &win -> xevent); // oops this blocks
    translateEvent(&win -> xevent, e);
    return true;
}

bool waitEvent(Window *win, Event *e) {
    XNextEvent(win -> d, &win -> xevent);
    translateEvent(&win -> xevent, e);
    return true;
}

void close(Window*) {

}

void requestFocus(Window*) {

}

void setSize(Window *win, uint32_t width, uint32_t height) {
    XResizeWindow(win -> d, win -> w, width, height);
}

void getSize(Window*, uint32_t*, uint32_t*) {

}

void setPosition(Window *win, int32_t x, int32_t y) {
    XMoveWindow(win -> d, win -> w, x, y);
}

void getPosition(Window*, int32_t*, int32_t*) {

}

// Platform specific functions

void setBorderWidth(Window* win, uint32_t width) {
    XSetWindowBorderWidth(win -> d, win -> w, width);
}
