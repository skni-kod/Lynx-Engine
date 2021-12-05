#include "Platform/C/LynxWindow.h"

struct LynxWindow {
    SOMEHANDLETYPE handle;
    ...
};

LynxWindow* createWindow() {

}

bool destroyWindow(LynxWindow*) {

}

bool pollEvent(LynxWindow*, Event*) {

}

bool waitEvent(LynxWindow*, Event*) {

}

void close(LynxWindow*) {

}

void requestFocus(LynxWindow*) {

}

void setSize(LynxWindow*, uint32_t, uint32_t) {

}

void getSize(LynxWindow*, uint32_t*, uint32_t*) {

}

void setPosition(LynxWindow*, int32_t, int32_t) {

}

void getPosition(LynxWindow*, int32_t*, int32_t*) {

}
