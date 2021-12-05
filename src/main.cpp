#include <iostream>
#include "Platform/C/Window.h"

int main() {
    auto window = createWindow();
    Event e;
    while(1)
        waitEvent(window, &e);
    return 0;
}
