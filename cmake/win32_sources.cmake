file(GLOB_RECURSE win32_SOURCES "src/*/Windows/*.cpp")
add_executable(lynx WIN32 ${win32_SOURCES})
target_link_libraries(lynx ${LIBS})