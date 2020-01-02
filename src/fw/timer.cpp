/**
 * @file timer.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the framework timer class
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <engine.h>
#include <fw/timer.h>
#include <fw/time.h>
#include <SFML/System.hpp>

using namespace be;

Timer::Timer(): m_clock()
{
    reset();
}

void Timer::reset()
{
    m_clock.restart();
}

float Timer::getElapsedTimeSeconds()
{
    return Time(m_clock.getElapsedTime()).getSeconds();
}

uint32_t Timer::getElapsedTimeMilliSeconds()
{
    return Time(m_clock.getElapsedTime()).getMilliSeconds();
}
uint64_t Timer::getElapsedTimeMicroSeconds()
{
    return Time(m_clock.getElapsedTime()).getMicroSeconds();
}