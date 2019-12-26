/**
 * @file eventdispatcher.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief The functions for the eventdispatcher class, only bindEvent and unBindEvent should be used directly by the game developer
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <core.h>
#include <engine/gameobjects/component.h>
#include <engine/eventdispatcher.h>

using namespace be;

EventDispatcher::EventDispatcher()
{
    m_hasParent = false;
    m_eventParent = NULL;
}

EventDispatcher::EventDispatcher(EventDispatcher *parent)
{
    m_hasParent = true;
    m_eventParent = parent;
}

void EventDispatcher::bindEvent(Component *component, unsigned int eventType)
{
    if (m_hasParent)
        m_eventParent->bindEvent(component, eventType);
    
    else
        m_eventPointers[eventType].push_back(component);
    
}

void EventDispatcher::unBindEvent(Component *component, unsigned int eventType)
{
    auto index = std::find(m_eventPointers[eventType].begin(), m_eventPointers[eventType].end(), component);
    if (index != m_eventPointers[eventType].end())
    {
        if (m_hasParent)
            m_eventParent->unBindEvent(component, eventType);
        else
            m_eventPointers[eventType].erase(index);
    }
    
}

void EventDispatcher::onEvent(Event *event)
{
    for (Component *component : m_eventPointers[event->type])
    {
        // @todo add more events
        switch (event->type)
        {
        case Event::keyPressed:
            component->keyPressEvent(event);
            break;
        case Event::keyReleased:
            component->keyReleaseEvent(event);
            break;
        case Event::mouseMoved:
            component->mouseMoveEvent(event);
            break;
        }
    }
}
