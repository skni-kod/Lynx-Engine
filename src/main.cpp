#include <iostream>
#include "../include/LynxWindow.h"

int main() {
    LynxWindow window;
    while(1)
        window.waitEvent();
    return 0;
}
