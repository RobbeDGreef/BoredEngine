/**
 * @file event.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the event class, aswell as the used event structures
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_EVENT_H
#define BE_EVENT_H

#include <SFML/Graphics.hpp>

namespace be
{

typedef struct keyEvent_struct
{
    int keyCode;
    bool alt;
    bool ctrl;
    bool shift;
    bool system;
} KeyEvent;

typedef struct MouseMoveEvent_struct
{
    int x;
    int y;
} MouseMoveEvent;

typedef struct MouseButtonPressedEvent_struct
{
    int button;
} MouseButtonPressedEvent;

typedef struct MouseButtonReleasedEvent_struct
{
    int button;
} MouseButtonReleasedEvent;


typedef struct MouseWheelEvent_struct
{
    int delta;
} MouseWheelEvent;

class Event
{
public:
 
    enum EventTypes
    {
        unknown = 0,
        closedWindow,
        resizedWindow,
        keyPressed,
        keyReleased,
        mouseMoved,
        mouseButtonPressed,
        mouseButtonReleased,
        mouseWheelScrolled,

        // @todo: implment touch events, joystick events and custom events

        END 
    };

    bool handled = false;
    unsigned int type = 0;

    // All event  types come here
    union
    {
        KeyEvent keyPress;
        KeyEvent keyRelease;
        MouseMoveEvent mouseMove;
        MouseButtonPressedEvent mouseButtonPress;
        MouseButtonReleasedEvent mouseButtonRelease;
        MouseWheelEvent mouseWheel;
    };
};

}

#endif // BE_EVENT_H