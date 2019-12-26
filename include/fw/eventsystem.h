/**
 * @file eventsystem.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the eventsystem class, should not be used directly by the game developer
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_EVENTSYS_H
#define BE_EVENTSYS_H

#include <fw/window.h>

#include <core.h>
#include <fw/event.h>

//#include <engine/component.h>


namespace be
{

class EventSystem
{

private:
    std::queue <Event> m_eventQueue;
    Window *m_window;
    bool m_running;

    Vector2 <int> *m_mousePointer;

public:
    unsigned int eventAmount = 0;
    EventSystem(Window *);
    std::queue <Event> *getEventQueue();
    bool onUpdate();

};

}

#endif // BE_EVENTSYS_H