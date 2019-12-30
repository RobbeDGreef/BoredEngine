/**
 * @file game.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the main game class, this class should not be used directly by the game developer
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_GAME_h
#define BE_GAME_h

#include <fw/window.h>
#include <fw/event.h>
#include <fw/eventsystem.h>

#include <engine/layerstack.h>
#include <engine/rendersystem.h>
#include <engine/gamecontext.h>

#include <core.h>

namespace be
{

class Game
{

private:
    Window *m_window;
    LayerStack *m_layerStack;
    EventSystem *m_eventSystem;
    RenderSystem *m_renderSystem;
    GameContext *m_gameContext;

    bool m_running = true;
    bool m_minimized = false;
    bool m_eventReceived = false;

public:
    // @todo: remove lvl entry point
    Game();
    ~Game();
    void pushLayer(Layer*);
    void insertLayer(Layer*, unsigned int layerIndex);
    void removeLayer(Layer*);
    void checkEvents();
    void reactEvent(Event*);

    void launch();

};

}

#endif // BE_GAME_h