#include <iostream>
#include "../include/LynxWindow.h"

int main() {
    LynxWindow window;
    Event e;
    while(1)
        window.waitEvent(e);
    return 0;
}
