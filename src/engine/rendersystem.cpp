/**
 * @file rendersystem.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the rendersystem class, these functions should not be used directly by the game developer
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <engine/rendersystem.h>
#include <engine/gameobjects/component.h>

using namespace be;

/**
 * @brief Recursive render function that renders all the children of a component parent, and the component parent itself.
 * 
 * @param renderList The to render component parent
 */
void RenderSystem::onRender(ComponentParent *renderList)
{
    for (Component *comp : renderList->getChildren())
    {
        if (comp->isParent())
        {
            onRender(dynamic_cast<ComponentParent*>(comp));
        }

        if (comp->isRenderable())
        {
            m_window->render(dynamic_cast<Sprite*>(comp));
        }
    }    
}

/**
 * @brief Construct a new Render System:: Render System object
 * 
 * @param window The window parameter to save
 */
RenderSystem::RenderSystem(Window *window)
{
    m_window = window;
}
