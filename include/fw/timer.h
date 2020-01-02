/**
 * @file timer.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the framework timer class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_TIMER_H
#define BE_TIMER_H

#include <SFML/System.hpp>
#include <engine.h>

namespace be
{

class Timer
{

private:
    sf::Clock m_clock;

public:

    Timer();
    void reset();
    float getElapsedTimeSeconds();
    uint32_t getElapsedTimeMilliSeconds();
    uint64_t getElapsedTimeMicroSeconds();
};

}

#endif // BE_TIMER_H