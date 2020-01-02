/**
 * @file eventsystem.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief This file implements the functions for the framework eventsystem class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <SFML/Window.hpp>

#include <fw/eventsystem.h>
#include <fw/event.h>
#include <fw/window.h>

#include <engine.h>


using namespace be;

EventSystem::EventSystem(Window *window)
{
    m_window = window;
    m_mousePointer = new Vector2 <int> (0,0);
    
}

std::queue <Event> *EventSystem::getEventQueue()
{
    return &m_eventQueue;
}

bool EventSystem::onUpdate()
{
    sf::Event sfEvent;
    
    Event beEvent;
    while (m_window->getWindow()->pollEvent(sfEvent))
    {
        switch (sfEvent.type)
        {
        case sf::Event::Closed:
            beEvent.type = Event::closedWindow;
            break;
        
        case sf::Event::KeyPressed:
            beEvent.type = Event::keyPressed;
            beEvent.keyPress.keyCode = sfEvent.key.code;
            break;
        
        case sf::Event::MouseMoved:
            m_mousePointer->x = sfEvent.mouseMove.x;
            m_mousePointer->y = sfEvent.mouseMove.y;
            beEvent.type = Event::mouseMoved;
            beEvent.mouseMove.x = sfEvent.mouseMove.x;
            beEvent.mouseMove.y = sfEvent.mouseMove.y;
            break;
        

        // @todo: reform all the events

        default:
            beEvent.type = Event::unknown;
            break;
        }
        
        m_eventQueue.push(beEvent);
        eventAmount++;
    }
    if (eventAmount)
        return true;
    
    return false;
}
