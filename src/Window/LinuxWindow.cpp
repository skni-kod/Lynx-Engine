#include "../../include/Config.h"

#if defined(LYNX_PLATFORM_LINUX)

#include "LinuxWindow.h"
#include "cstdlib"

LinuxWindow::LinuxWindow() {
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

LinuxWindow::~LinuxWindow(){
    XCloseDisplay(d);
}

bool LinuxWindow::waitEvent() {
    XNextEvent(d, &e);
    return true;
}

bool LinuxWindow::poolEvent() {
    XNextEvent(d, &e); // oops this blocks
    return true;
}

#endif // LYNX_PLATFORM_LINUX