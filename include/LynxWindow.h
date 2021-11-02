#ifndef LYNX_ENGINE_LYNXWINDOW_H
#define LYNX_ENGINE_LYNXWINDOW_H

#include "Config.h"

#if defined(LYNX_PLATFORM_WINDOWS)
    #include "../src/Window/Win32Window.h"
    typedef Win32Window LynxWindow;

#elif defined(LYNX_PLATFORM_LINUX)
    #include "../src/Window/LinuxWindow.h"
    typedef LinuxWindow LynxWindow;

#elif defined(LYNX_PLATFORM_MACOS)
    #include "../src/Window/MacOSWindow.h"
    typedef MacOSWindow LynxWindow;

#endif
#endif //LYNX_ENGINE_LYNXWINDOW_H
