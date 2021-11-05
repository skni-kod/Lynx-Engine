#ifndef LYNX_ENGINE_MACOSWINDOW_H
#define LYNX_ENGINE_MACOSWINDOW_H

#include "../Config.h"

#if defined(LYNX_PLATFORM_MACOS)

class LynxWindow  {
public:
    LynxWindow();
    ~LynxWindow();
    bool pollEvent();
    bool waitEvent();
private:
    ...
};

#endif
#endif //LYNX_ENGINE_MACOSWINDOW_H
