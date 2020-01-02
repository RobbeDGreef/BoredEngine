/**
 * @file engine.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief The main core header file, holds all the default engine types aswell as some standard library headers
 * @version 0.2
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_ENGINE_H
#define BE_ENGINE_H

#include <iostream>
#include <fstream>

#include <cmath>

#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define GETBIT(x) (1 << x)

namespace be
{

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
    Vector2() { x=0; y=0; }
    Vector2(vecT _x, vecT _y) { x=_x; y=_y; }
    Vector2(const Vector2 <vecT> &old) { x=old.x; y=old.y; } 
    
    Vector2<vecT> operator+(const Vector2<vecT>&); 
    Vector2<vecT> operator*(const Vector2<vecT>&);

    Vector2<vecT>& operator+=(const Vector2<vecT> a)
    {
        x += a.x;
        y += a.y;
        return *this;
    }

    Vector2<vecT>& operator*=(const Vector2<vecT> a)
    {
        x *= a.x;
        y *= a.y;
        return *this;
    }

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

    Vector3<vecT> operator+(const Vector3<vecT>&); 
    Vector3<vecT> operator*(const Vector3<vecT>&);

    Vector3<vecT>& operator+=(const Vector3<vecT> a)
    {
        x += a.x;
        y += a.y;
        return *this;
    }

    Vector3<vecT>& operator*=(const Vector3<vecT> a)
    {
        x *= a.x;
        y *= a.y;
        return *this;
    }

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

} // namespace be

#endif // BE_ENGINE_H