#ifndef LYNX_ENGINE_WINDOW_H
#define LYNX_ENGINE_WINDOW_H


class Window {
public:
    Window();
    void close();
    bool poolEvent();
    bool waitEvent();
};


#endif //LYNX_ENGINE_WINDOW_H
