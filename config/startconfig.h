/**
 * @file startconfig.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Default game start configurations, like start level etc
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_STARTCONFIG_H
#define BE_STARTCONFIG_H

#include <engine/gamecontext.h>

#include <engine/gameobjects/playercontroller.h>
#include <engine/gameobjects/level.h>

class GAMECONTEXT: public be::GameContext
{
public:
    /**
     * @brief Construct a new GAMECONTEXT object
     * 
     * @note I know code in header files is not good practice but I'm trying
     *       to make it easier for the developer to configure their game.
     */
    GAMECONTEXT()
    {
        /**
         * To change the startlevel, playercontroller etc import your own derived classes
         * and change the classes after the 'new' specifier to your classes.
         */
        level = new Level(this);
        playerController = new PlayerController(level->root);
    }
};

#endif // BE_STARTCONFIG_H