/**
 * @file layerstack.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the layerstack system class, while it is perfectly possible, it is not recommended for the developer to use these functions directly
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <engine/layerstack.h>
#include <engine/layer.h>
#include <engine/rendersystem.h>

#include <core.h>

using namespace be;

LayerStack::~LayerStack()
{
    for (Layer *layer : m_layerStack)
    {
        removeLayer(layer);
    }
}

void LayerStack::pushLayer(Layer *layer)
{
    m_layerStack.push_back(layer);
    layer->onAttach();
}

void LayerStack::insertLayer(Layer *layer, unsigned int layerIndex)
{
    // @todo : insert layers
    std::cout << "This feature is not implemented yet!\n";
    //m_layerStack.insert(layerIndex, layer);
}

void LayerStack::removeLayer(Layer *layer)
{
    auto i = std::find(m_layerStack.begin(), m_layerStack.end(), layer);
    if (i != m_layerStack.end())
    {
        layer->onDetach();
        delete layer;
        m_layerStack.erase(i);
    }
}

void LayerStack::receivedEvent(Event *event)
{

    for (auto i = m_layerStack.rbegin(); i != m_layerStack.rend(); ++i)
    {
        if (event->handled == false)
            
            (*i)->onEvent(event);
        else
            return;
    }
}

void LayerStack::update()
{
    for (Layer *layer: m_layerStack)
    {
        layer->update();
    }
}

void LayerStack::render(RenderSystem *renderSystem)
{
    for (Layer *layer : m_layerStack)
    {
        if (layer->isRenderAble())
        {
            renderSystem->onRender(layer->root);
        }
    }
}