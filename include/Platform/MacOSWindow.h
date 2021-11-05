#ifndef LYNX_ENGINE_MACOSWINDOW_H
#define LYNX_ENGINE_MACOSWINDOW_H

#include "../Config.h"

#if defined(LYNX_PLATFORM_MACOS)

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
#endif //LYNX_ENGINE_MACOSWINDOW_H
