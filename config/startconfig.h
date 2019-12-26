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

// Uncomment this next two lines and reference your own startlevel in the same manner, the name of the time should still be STARTLEVEL
#include <engine/gameobjects/level.h>
using STARTLEVEL = be::Level;

#endif // BE_STARTCONFIG_H