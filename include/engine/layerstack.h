/**
 * @file layerstack.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the layerstack class, this class should not be used by the game developer directly, the functions can be.
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_LAYERSTACK_H
#define BE_LAYERSTACK_H

#include <engine/layer.h>
#include <engine/rendersystem.h>
#include <core.h>

namespace be
{

class LayerStack
{
private:
    std::vector <Layer*> m_layerStack;
    unsigned int m_layerAmount = 0;

public:
    ~LayerStack();
    void pushLayer(Layer*);
    void insertLayer(Layer*, unsigned int layerIndex);
    void removeLayer(Layer*);

    void update();
    void render(RenderSystem *);
    void receivedEvent(Event*);

};

}

#endif // BE_LAYERSTACK_H