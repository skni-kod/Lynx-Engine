#ifndef LYNX_ENGINE_TEMPLATEWINDOW_H
#define LYNX_ENGINE_TEMPLATEWINDOW_H

#include "../Config.h"
#if defined(LYNX_PLATFORM_EXAMPLE_PLATFORM)

#include "../Event.h"
#include ...

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
    // Any OS specific variables go here
};

#endif
#endif

