/**
 * @file game.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief This file implements the functions for the main game class, these functions should not be used directly by the game developer
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <fw/timer.h>
#include <fw/thread.h>
#include <engine/game.h>
#include <engine/gameobjects/level.h>
#include <startconfig.h>
#include <config.h>

using namespace be;

/**
 * @note: the level entry point like this will be removed in the future when the default startlevel 
 *        gets defined via another way
 * @todo: remove level entry point like this
 */

Game::Game()
{
    m_window = new Window(BE_WINDOW_TITLE, BE_WINDOW_WIDTH, BE_WINDOW_HEIGHT);
    m_layerStack = new LayerStack();
    m_eventSystem = new EventSystem(m_window);
    m_renderSystem = new RenderSystem(m_window);

    m_layerStack->pushLayer(new STARTLEVEL());

}

Game::~Game()
{
    delete m_renderSystem;
    delete m_eventSystem;
    delete m_layerStack;
    delete m_window;
}

void Game::pushLayer(Layer *layer)
{
    m_layerStack->pushLayer(layer);
}

void Game::insertLayer(Layer *layer, unsigned int layerIndex)
{
    m_layerStack->insertLayer(layer, layerIndex);
}

void Game::removeLayer(Layer *layer)
{
    m_layerStack->removeLayer(layer);
}

void Game::reactEvent(Event *event)
{
    switch (event->type)
    {
    case Event::closedWindow:
        m_running = false;
        event->handled = true;
        break;
    }

}
void Game::checkEvents()
{
    // @todo: maybe we should do this in the layer stack and not call the layer stack
    auto eventQueue = m_eventSystem->getEventQueue();
    unsigned int iterMax = eventQueue->size();
    
    Event event;
    for (unsigned int i = 0; i < iterMax; i++)
    {
        event = eventQueue->front();
        
        // We capture the closewindow, resizewindow and focus events and dispatch them to the application
        if (event.type < 3)
            reactEvent(&event);
        else
            m_layerStack->receivedEvent(&event);
        
        eventQueue->pop();
        m_eventSystem->eventAmount--;
    }
    
}

void Game::launch()
{
    Timer timer = Timer();

    while (m_running)
    {
        //std::cout << "fps: " << 1 / timer.getElapsedTimeSeconds() << std::endl;;
        timer.reset();
        m_window->clear(BACKGROUNDCOLOR);
        m_eventSystem->onUpdate();
        checkEvents();
        m_layerStack->update();
        m_layerStack->render(m_renderSystem);

        m_window->display();
    }
}