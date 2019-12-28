/**
 * @file component.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the Component and ComponentParent classes
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#include <engine/gameobjects/component.h>
#include <engine/movesystem.h>
#include <fw/eventsystem.h>
#include <core.h>

using namespace be;

Component::Component(ComponentParent *parent, int type, bool receivesEvents, bool isParent)
    : Transformable()
{
    m_parent = parent;
    m_sceneRoot = false;

    m_type = type;
    m_events = receivesEvents;
    m_isParent = isParent;
    
    parent->addChild(this);

}

Component::Component(MoveSystem *movesys) : Transformable()
{
    m_sceneRoot = true;
    m_parent = NULL;
    m_moveSystem = movesys;

    m_type = Component::ComponentType::SceneRoot;
    m_events = true;
    m_isParent = false;
}

void Component::setParent(ComponentParent *parent)
{
    m_parent = parent;
}

Vector2 <float> Component::getWorldLocation() 
{
    Vector2 <float> ret(m_location);
    if (m_parent)
    {
        ret.add(m_parent->getLocation());
    }
    return ret;
}

Rotator <float> Component::getWorldRotation()
{
    Rotator <float> ret(m_rotation);
    if (m_parent)
    {
        ret.rot += m_parent->getRotation().rot;
    }
    return ret;
}

Vector2 <float> Component::getWorldScale()
{
    Vector2 <float> ret(m_scale);
    
    if (m_parent)
    {
        ret.multiply(m_parent->getScale());
    }
    return ret;
}

void ComponentParent::addChild(Component *child)
{
    m_children.push_back(child);
}

void ComponentParent::addChild(Component *child, Vector2 <float> location, Rotator <float> rotation, Vector2 <float> scale)
{

    m_children.push_back(child);
    set(location, rotation, scale);
}


ComponentParent::ComponentParent(MoveSystem *movesys, EventDispatcher *ed): Component(movesys), EventDispatcher(ed)
{
    
}

ComponentParent::ComponentParent(ComponentParent *parent, bool render, bool event): Component(parent, Component::ComponentType::Actor, event, true), EventDispatcher(parent)
{

}