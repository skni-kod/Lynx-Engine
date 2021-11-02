cmake_minimum_required(VERSION 3.21)
project(lynx-engine)

set(CMAKE_CXX_STANDARD 11)

add_executable(lynx-engine src/main.cpp src/Window/Win32Window.cpp include/Window.h src/Window/LinuxWindow.cpp src/Window/OSXWindow.cpp include/Config.h)
