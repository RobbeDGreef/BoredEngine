/**
 * @file main.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief The main entry point for the game
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <config.h>

#include <engine/game.h>

#include <engine/gameobjects/level.h>
#include <engine/gameobjects/component.h>

#include <fw/sprite.h>
#include <fw/texture.h>
#include <fw/keyboard.h>

using namespace be;

int main()
{
    std::cout << "Game started\n";
    Game game = Game();
    game.launch();
}