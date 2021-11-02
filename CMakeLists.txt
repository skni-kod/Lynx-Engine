cmake_minimum_required(VERSION 3.21)
project(lynx-engine)

set(CMAKE_CXX_STANDARD 11)

add_executable(lynx-engine src/main.cpp src/Window/Win32Window.cpp src/Window/WindowBase.h src/Window/LinuxWindow.cpp src/Window/MacOSWindow.cpp include/Config.h include/LynxWindow.h src/Window/Win32Window.h src/Window/LinuxWindow.h src/Window/MacOSWindow.h)
target_link_libraries(lynx-engine X11)