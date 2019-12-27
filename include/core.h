/**
 * @file core.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief The main core header file, holds all the default engine types aswell as some standard library headers
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_CORE_H
#define BE_CORE_H

#include <iostream>
#include <fstream>

#include <cmath>

#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define GETBIT(x) (1 << x)

/**
 * Default engine types
 */


template <typename vecT>
class Vector2
{
public:
    vecT x = 0;
    vecT y = 0;

public:
    Vector2(vecT _x, vecT _y) { x=_x; y=_y; }
    Vector2(const Vector2 <vecT> &old) { x=old.x; y=old.y; } 
    
    void add(Vector2 <vecT> amount) { x+=amount.x; y+=amount.y; }
    void multiply(Vector2 <vecT> amount) { x*=amount.x; y*=amount.y; }
};

template <typename vecT>
class Vector3
{
public:
    vecT x = 0;
    vecT y = 0;
    vecT z = 0;

public:
    Vector3(const Vector3 <vecT> &old) { x=old.x; y=old.y; z=old.z; }
    Vector3(vecT _x, vecT _y, vecT _z) { x=_x; y=_y; z=_z; }

    void add(Vector3 <vecT> amount) { x+=amount.x; y+=amount.y; z+=amount.z; }
    void multiply(Vector3 <vecT> amount) { x*=amount.x; y*=amount.y; z*=amount.z; }
};

template <typename rotT>
class Rotator
{
public:
    rotT rot = 0;

public:
    Rotator <rotT> (const Rotator <rotT> &old) { rot=old.rot; }
    Rotator <rotT> (rotT rot) { rot=rot; }
};

#endif // BE_CORE_H