#include <iostream>
#include "Platform/C/LynxWindow.h"

int main() {
    auto window = createWindow();
    Event e;
    while(1)
        waitEvent(window, &e);
    return 0;
}
