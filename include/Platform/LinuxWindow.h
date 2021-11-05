#ifndef LYNX_ENGINE_LINUXWINDOW_H
#define LYNX_ENGINE_LINUXWINDOW_H

#include "../Config.h"

#if defined(LYNX_PLATFORM_LINUX)

#include <X11/Xlib.h>

class LynxWindow  {
public:
    LynxWindow();
    ~LynxWindow();
    bool pollEvent();
    bool waitEvent();
private:
    Display *d;
    Window w;
    XEvent e;
    int s;
};

#endif
#endif //LYNX_ENGINE_LINUXWINDOW_H
