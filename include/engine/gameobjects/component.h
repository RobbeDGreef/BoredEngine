/**
 * @file component.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the component and componentparent class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_COMPONENT_H
#define BE_COMPONENT_H

#include <engine/transformable.h>
#include <fw/event.h>
#include <engine/eventdispatcher.h>
#include <core.h>

namespace be
{

class ComponentParent;

class Component : public Transformable
{

/**
 * Hersenspinsels:
 * so if this is an actor he needs to handle that completely like a new one right ? but with transformable 
 * info of the parent? so that means that every actor somehow is a level too ?
 * ok so if that's true that means we could create a class that holds a list of components (including actors)
 * and inherit actor from this class AND component right? or nONONON better idea
 * 
 * let's make component also hold transformable info yeayeayea that's better and that way every actor holds it's own work postition etc
 * which makes so much more sense really
 * 
 * so to recap
 * actor -> inherits from component
 * component -> inherits from transformable class
 * component: renderable, code exec etc...
 */
private:
    bool m_renderAble;
    bool m_events;
    bool m_isParent;
    
    bool m_sceneRoot;
    ComponentParent *m_parent;

public:
    int gameState;

public:
    // Engine functions 
    Component(bool);
    Component(ComponentParent *, bool, bool, bool);
    virtual void onRender() {}

    bool isRenderable() { return m_renderAble; }
    bool isParent() { return m_isParent; }
    bool getsEvents() { return m_events; }

    // Functions called by user of engine 

    // The set parent function will be called once the child is added to the parent
    void setParent(ComponentParent *parent);

    virtual void keyPressEvent(Event *) {}
    virtual void keyReleaseEvent(Event *) {}
    virtual void mouseMoveEvent(Event *) {}
    virtual void mouseButtonPressEvent(Event*) {}
    virtual void mouseButtonReleaseEvent(Event*) {}
    virtual void mouseWheelScrolled(Event *) {}

    Vector2 <float> getWorldLocation();
    Rotator <float> getWorldRotation();
    Vector2 <float> getWorldScale();

};

class ComponentParent : public Component, public EventDispatcher
{
protected:
    std::vector <Component*> m_children;

public:
    void addChild(Component *);
    void addChild(Component *, Vector2 <float> , Rotator <float> , Vector2 <float>);
    
    auto getChildren() { return m_children; }
    ComponentParent(EventDispatcher *ed);
    ComponentParent(ComponentParent *parent, bool render, bool event);
};

}


#endif // BE_COMPONENT_H