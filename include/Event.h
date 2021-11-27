#ifndef LYNX_ENGINE_EVENT_H
#define LYNX_ENGINE_EVENT_H

#include "cstdint"
#include "Enums.h"

// Blatantly ~~stolen from~~ *inspired by* SFML (Event.hpp)
class Event {
    public:
    enum class EventType : uint8_t {
        Closed,
        Resized,
        LostFocus,
        GainedFocus,
        TextEntered,
        KeyPressed,
        KeyReleased,
        MouseWheelMoved,
        MouseWheelScrolled,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseEntered,
        MouseLeft,
        JoystickButtonPressed,
        JoystickButtonReleased,
        JoystickMoved,
        JoystickConnected,
        JoystickDisconnected,
        TouchBegan,
        TouchMoved,
        TouchEnded,
        SensorChanged,

        Count
    };

    struct ResizedEvent {
        uint32_t width;
        uint32_t height;
    };

    struct KeyEvent {
        enum ModBit : uint8_t {
            ALT     =   1 << 0,
            CTRL    =   1 << 1,
            SHIFT   =   1 << 2,
            SUPER   =   1 << 3
        };

        Key key;
        ModBit modifiers;

        inline bool isAltPressed() const {
            return modifiers & ModBit::ALT;
        }

        inline bool isCtrlPressed() const {
            return modifiers & ModBit::CTRL;
        }

        inline bool isShiftPressed() const {
            return modifiers & ModBit::SHIFT;
        }

        inline bool isSuperPressed() const {
            return modifiers & ModBit::SUPER;
        }
    };

    EventType type;

    union {
        ResizedEvent resizedEvent;
        KeyEvent keyEvent;
    };
};

#endif //LYNX_ENGINE_EVENT_H
