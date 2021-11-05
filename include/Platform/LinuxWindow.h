#ifndef LYNX_ENGINE_LINUXWINDOW_H
#define LYNX_ENGINE_LINUXWINDOW_H

#include "../Config.h"

#if defined(LYNX_PLATFORM_LINUX)

#include "../Event.h"
#include <X11/Xlib.h>

class LynxWindow  {
public:
    LynxWindow();
    ~LynxWindow();
    bool pollEvent(Event&);
    bool waitEvent(Event&);
    void close();
    void requestFocus();
    void setSize(uint32_t, uint32_t);
    void getSize(uint32_t&, uint32_t&);
    void setPosition(uint32_t, uint32_t);
    void getPosition(uint32_t&, uint32_t&);

private:
    Display *d;
    Window w;
    XEvent xevent;
    int s;
};

#endif
#endif //LYNX_ENGINE_LINUXWINDOW_H
