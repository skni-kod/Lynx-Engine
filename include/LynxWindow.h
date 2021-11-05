#ifndef LYNX_ENGINE_LYNXWINDOW_H
#define LYNX_ENGINE_LYNXWINDOW_H

#include "Event.h"

class LynxWindow {
public:
    LynxWindow();
    ~LynxWindow();
    bool pollEvent(Event&);
    bool waitEvent(Event&);
};

#endif //LYNX_ENGINE_LYNXWINDOW_H
