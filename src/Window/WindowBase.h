#ifndef LYNX_ENGINE_WINDOWBASE_H
#define LYNX_ENGINE_WINDOWBASE_H


class WindowBase {
public:
    //virtual void close() = 0;
    virtual bool poolEvent() = 0;
    virtual bool waitEvent() = 0;
};


#endif //LYNX_ENGINE_WINDOWBASE_H
