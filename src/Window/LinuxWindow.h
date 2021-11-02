#ifndef LYNX_ENGINE_LINUXWINDOW_H
#define LYNX_ENGINE_LINUXWINDOW_H

#include "../../include/Config.h"

#if defined(LYNX_PLATFORM_LINUX)

#include "WindowBase.h"
#include <X11/Xlib.h>

class LinuxWindow : WindowBase {
public:
    LinuxWindow();
    ~LinuxWindow();
    bool poolEvent() override;
    bool waitEvent() override;
private:
    Display *d;
    Window w;
    XEvent e;
    int s;
};

#endif
#endif //LYNX_ENGINE_LINUXWINDOW_H
