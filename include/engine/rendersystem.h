/**
 * @file rendersystem.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the rendersystem class, should not be used directly by the game developer
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_RENDERSYS_h
#define BE_RENDERSYS_h

#include <fw/window.h>
#include <engine/gamecontext.h>
#include <engine/gameobjects/component.h>


namespace be
{

#define PIXEL_TO_METER_RATIO    15 ///< 15 pixels per meter (on no zoom 20 m camera distance)

/**
 * maybe render calls should be sent to the window class, altough that would make rendercanvases impossible ? or maybe not if i emmulate them
 * with a framework class and then inheriting the window class from a rendercanvas ? but i don't really think rendercanvases are a necessity right now
*/

class RenderSystem
{
private: 
    // @todo: Create a camera system (might put it in window class but it needs to be able to change and created by the user)
    Window *m_window;
    GameContext *m_gameContext;

public:
    RenderSystem(Window *, GameContext *);

    // recursive render function over componentparents ?
    void onRender(ComponentParent *);
    
};

}


#endif // BE_RENDERSYS_h
