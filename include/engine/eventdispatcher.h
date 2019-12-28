/**
 * @file eventdispatcher.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the event dispatcher class, this class should not be used directly by the developer, the functions can be.
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_EVENTDISPATCH_H
#define BE_EVENTDISPATCH_H

#include <fw/event.h>
#include <engine/gameobjects/component.h>
#include <core.h>


namespace be
{

// Forward declair to component.h, if we didn't we would get multiple include problems
class Component;

class EventDispatcher
{
private:
    bool m_hasParent = false;
    EventDispatcher *m_eventParent;
    std::vector<Component*> m_eventPointers[Event::EventTypes::END-1];

public:
    EventDispatcher();
    EventDispatcher(EventDispatcher *); // if this event dispatcher has a parent this constructor will be used

    void onEvent(Event *);
    void bindEvent(Component *, unsigned int);
    void unBindEvent(Component *, unsigned int);

};

}

#endif // BE_EVENTDISPATCH_H