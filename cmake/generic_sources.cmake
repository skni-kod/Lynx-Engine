file(GLOB_RECURSE generic_SOURCES "src/*/Generic/*.cpp")
target_sources(lynx PRIVATE ${generic_SOURCES})