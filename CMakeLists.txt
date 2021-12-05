cmake_minimum_required(VERSION 3.21)
project(lynx-engine)

set(CMAKE_CXX_STANDARD 11)

# Headers
include_directories(include)
add_executable(lynx-engine src/main.cpp include/Config.h include/Enums.h include/Event.h include/Platform/C/LynxWindow.h)

# Sources
SET(PLATFORM_SOURCES Window.cpp)
LIST(TRANSFORM PLATFORM_SOURCES PREPEND src/Platform/${CMAKE_SYSTEM_NAME}/)

target_sources(lynx-engine PRIVATE ${PLATFORM_SOURCES})

target_link_libraries(lynx-engine X11)

# TODO: Move lib linking to separate files