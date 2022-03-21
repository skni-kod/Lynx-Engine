cmake_minimum_required(VERSION 3.21)

project(lynx-engine)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

include(cmake/platform_sources.cmake)
include(cmake/platform_libraries.cmake)

include_directories(include)

# Sources
add_executable(lynx-engine src/main.cpp)
LIST(TRANSFORM PLATFORM_SOURCES PREPEND src/Platform/${CMAKE_SYSTEM_NAME}/)
target_sources(lynx-engine PRIVATE ${PLATFORM_SOURCES})

find_package(OpenGL REQUIRED)
add_dependencies(lynx-engine OpenGL::GL)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(lynx-engine OpenGL::GL ${PLATFORM_LIBS})

