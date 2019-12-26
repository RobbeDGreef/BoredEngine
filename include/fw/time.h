/**
 * @file time.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the framework time class, note: this is not the same as the timer class, this class implements a wrapper for the sf::Time class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_TIME_H
#define BE_TIME_H

#include <SFML/System.hpp>

namespace be
{

class Time
{
private:
    sf::Time m_time;

public:
    Time(sf::Time time) { m_time = time; } 
    Time() {}

    float getSeconds() { m_time.asSeconds(); }
    uint32_t getMilliSeconds() { m_time.asMilliseconds(); }
    uint64_t getMicroSeconds() { m_time.asMicroseconds(); }

};

}

#endif // BE_TIME_H