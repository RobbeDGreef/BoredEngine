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
#include <engine/gameobjects/camera.h>
#include <engine/gameobjects/playercontroller.h>

using namespace be;

/**
 * @brief Recursive render function that renders all the children of a component parent, and the component parent itself.
 * 
 * @param renderList The to render component parent
 */
void RenderSystem::onRender(ComponentParent *renderList)
{
    Camera *camera = m_gameContext->getPlayerController()->getActiveCamera();

    for (Component *comp : renderList->getChildren())
    {
        if (comp->isParent())
        {
            onRender(dynamic_cast<ComponentParent*>(comp));
        }

        if (comp->getType() == Component::ComponentType::Renderable)
        {
            auto sprite = dynamic_cast<Sprite*>(comp);
            auto xloc = (sprite->getWorldLocation().x - camera->getWorldLocation().x) * PIXEL_TO_METER_RATIO * camera->getZoom();
            auto yloc = (sprite->getWorldLocation().y - camera->getWorldLocation().y) * PIXEL_TO_METER_RATIO * camera->getZoom();
            float zoomx = sprite->getWorldScale().x * camera->getZoom();
            float zoomy = sprite->getWorldScale().y * camera->getZoom();

            m_window->render(sprite, xloc, yloc, zoomx, zoomy);
        }
    }    
}

/**
 * @brief Construct a new Render System:: Render System object
 * 
 * @param window The window parameter to save
 */
RenderSystem::RenderSystem(Window *window, GameContext *gcontext)
{
    m_window = window;
    m_gameContext = gcontext;
}
