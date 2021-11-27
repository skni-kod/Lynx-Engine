cmake_minimum_required(VERSION 3.21)
project(lynx-engine)

set(CMAKE_CXX_STANDARD 11)

add_executable(lynx-engine src/main.cpp src/Platform/Win32/Window.cpp src/Platform/Linux/Window.cpp src/Platform/Template/Window.cpp src/Platform/MacOS/Window.cpp include/Config.h include/Enums.h include/Event.h include/Platform/Win32Window.h include/Platform/LinuxWindow.h include/Platform/MacOSWindow.h include/Platform/TemplateWindow.h include/Platform/C/LynxWindow.h)
include_directories(include)
target_link_libraries(lynx-engine X11)
