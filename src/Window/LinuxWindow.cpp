#include "../../include/Config.h"

#if defined(LYNX_PLATFORM_LINUX)

#include "../../include/Platform/LinuxWindow.h"
#include "cstdlib"

LynxWindow::LynxWindow() {
    d = XOpenDisplay(nullptr);
    if (d == nullptr) {
        exit(1); // TODO wywalić to
    }
    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 100, 100, 1,
                            BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapWindow(d, w);
}

LynxWindow::~LynxWindow(){
    XCloseDisplay(d);
}

bool LynxWindow::waitEvent(Event& e) {
    XNextEvent(d, &xevent);
    return true;
}

bool LynxWindow::pollEvent(Event& e) {
    XNextEvent(d, &xevent); // oops this blocks
    return true;
}

#endif // LYNX_PLATFORM_LINUX