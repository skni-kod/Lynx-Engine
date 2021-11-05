cmake_minimum_required(VERSION 3.21)
project(lynx-engine)

set(CMAKE_CXX_STANDARD 11)

add_executable(lynx-engine src/main.cpp src/Window/Win32Window.cpp src/Window/LinuxWindow.cpp src/Window/TemplateWindow.cpp src/Window/MacOSWindow.cpp include/Config.h include/Enums.h include/Event.h include/LynxWindow.h include/Platform/Win32Window.h include/Platform/LinuxWindow.h include/Platform/MacOSWindow.h include/Platform/TemplateWindow.h)
target_link_libraries(lynx-engine X11)