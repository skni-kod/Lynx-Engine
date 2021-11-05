#ifndef LYNX_ENGINE_LYNXWINDOW_H
#define LYNX_ENGINE_LYNXWINDOW_H

class LynxWindow {
public:
    LynxWindow();
    ~LynxWindow();
    bool pollEvent();
    bool waitEvent();
};

#endif //LYNX_ENGINE_LYNXWINDOW_H
