#ifndef LYNX_ENGINE_WIN32WINDOW_H
#define LYNX_ENGINE_WIN32WINDOW_H

#include "../Config.h"

#if defined(LYNX_PLATFORM_WINDOWS)

#include "../Event.h"

class LynxWindow  {
public:
    LynxWindow();
    ~LynxWindow();
    bool pollEvent(Event&);
    bool waitEvent(Event&);
private:
    ...
};

#endif
#endif //LYNX_ENGINE_WIN32WINDOW_H
