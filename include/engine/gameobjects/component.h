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

#include <engine/movesystem.h>
#include <engine/transformable.h>
#include <engine/eventdispatcher.h>
#include <fw/event.h>
#include <core.h>

namespace be
{

class MoveSystem;
class ComponentParent;

class Component : public Transformable
{

public:
    enum ComponentType
    {
        Collision,
        Renderable,
        SceneRoot,
        Actor
    };

private:
    int m_type; // Type of component see enum ComponentType
    bool m_events;
    bool m_isParent;
    ComponentParent *m_parent;
    
    bool m_sceneRoot;
    MoveSystem *m_moveSystem;

public:
   int gameState;

public:
    // Engine functions 
    Component(MoveSystem *movesys);
    Component(ComponentParent *, int type, bool event, bool parent);
    virtual void onRender() {}

    int getType() { return m_type; }
    void setType(int type) { m_type = type; }
    bool isParent() { return m_isParent; }
    ComponentParent *getParent() { return m_parent; }
    MoveSystem *getMoveParent(){ return m_moveSystem; }
    bool isSceneRoot() { return m_sceneRoot; }
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
    ComponentParent(MoveSystem *movesys, EventDispatcher *ed);
    ComponentParent(ComponentParent *parent, bool render, bool event);
};

}


#endif // BE_COMPONENT_H