#ifndef LYNX_ENGINE_CONFIG_H
#define LYNX_ENGINE_CONFIG_H


// Platforms
#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__CYGWIN__) || defined(__CYGWIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
    // Windows
    #define LYNX_PLATFORM_WINDOWS

#elif defined(__unix__)

    // UNIX systems
    #if defined(__linux__)
        // Linux
        #define LYNX_PLATFORM_LINUX

    #elif defined(__ANDROID__)
        // Android
        #error Ta platforma nie jest wspierana przez Lynx

    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
        // FreeBSD
        #error Ta platforma nie jest wspierana przez Lynx

    #else
        #error Ta platforma nie jest wspierana przez Lynx

    #endif

#elif defined(__APPLE__) && defined(__MACH__)
    #include "TargetConditionals.h"

    #if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
        // iOS
        #error Ta platforma nie jest wspierana przez Lynx

    #elif TARGET_OS_MAC
        // MacOS
        #define LYNX_PLATFORM_MACOS

    #else
        #error Ta platforma nie jest wspierana przez Lynx

    #endif

#elif
    #error Ta platforma nie jest wspierana przez Lynx

#endif
#endif //LYNX_ENGINE_CONFIG_H
