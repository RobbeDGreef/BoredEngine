/**
 * @file layer.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the layer class, while it is perfectly possible, it is not recommended for the developer to use these functions directly
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_LAYER_H
#define BE_LAYER_H

#include <core.h>
#include <fw/event.h>
#include <fw/eventsystem.h>

namespace be
{

class Layer : public EventDispatcher
{
public:
    ComponentParent *root;
    bool m_renderAble = false;

#ifdef DEBUG_BUILD
protected:
    std::string m_layerName;
#endif

public:

#ifdef DEBUG_BUILD
    Layer(std::string layername, bool isRenderAble);
#endif
    Layer(bool isRenderAble);
    
    virtual void onUpdate() {}
    virtual void onAttach() {}
    virtual void onDetach() {}

    bool isRenderAble() { return m_renderAble; }

#ifdef DEBUG_BUILD
    inline std::string getName() { return m_layerName; }
#endif

};

}

#endif //BE_LAYER_H