cmake_minimum_required(VERSION 3.21)
project(lynx-engine)

#TODO: this might be MSVC specific - check
add_definitions(-D_UNICODE -DUNICODE)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
endif()


include_directories(${lynx-engine_SOURCE_DIR}/include)




if(WIN32)
	set(WINDOWS TRUE)
	add_definitions(-D_WINDOW_)
endif()

set(CMAKE_CXX_STANDARD 17)

#OpenGL
find_package(OpenGL REQUIRED)
set(LIBS ${OPENGL_LIBRARY})


if(WINDOWS)
	include(cmake/include_win32.cmake)
	include(cmake/win32_sources.cmake)
endif()



include(cmake/include_generic.cmake)
include(cmake/generic_sources.cmake)
