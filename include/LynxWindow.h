#ifndef LYNX_ENGINE_LYNXWINDOW_H
#define LYNX_ENGINE_LYNXWINDOW_H

#include "Event.h"
#include "cstdint"


class LynxWindow {
public:
    LynxWindow();
    ~LynxWindow();
    bool pollEvent(Event&);
    bool waitEvent(Event&);
    void close();
    void requestFocus();
    void setSize(uint32_t, uint32_t);
    void getSize(uint32_t&, uint32_t&);
    void setPosition(int32_t, int32_t);
    void getPosition(int32_t &, int32_t &);
};

#endif //LYNX_ENGINE_LYNXWINDOW_H
