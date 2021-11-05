#ifndef LYNX_ENGINE_WIN32WINDOW_H
#define LYNX_ENGINE_WIN32WINDOW_H

#include "../Config.h"

#if defined(LYNX_PLATFORM_WINDOWS)

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
#endif //LYNX_ENGINE_WIN32WINDOW_H
