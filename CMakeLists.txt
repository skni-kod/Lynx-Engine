cmake_minimum_required(VERSION 3.21)
project(lynx-engine)

set(CMAKE_CXX_STANDARD 11)

include(cmake/platform_sources.cmake)
include(cmake/platform_libraries.cmake)

include_directories(include)

# Sources
add_executable(lynx-engine src/main.cpp)
LIST(TRANSFORM PLATFORM_SOURCES PREPEND src/Platform/${CMAKE_SYSTEM_NAME}/)
target_sources(lynx-engine PRIVATE ${PLATFORM_SOURCES})

target_link_libraries(lynx-engine ${PLATFORM_LIBS})
