/**
 * @file layer.cpp
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the functions for the layer class, while it is perfectly possible, it is not recommended for the developer to use these functions directly
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <core.h>

#include <engine/layer.h>

using namespace be;

Layer::Layer(bool isRenderAble)
{
    m_renderAble = isRenderAble;
    root = new ComponentParent(this);
}

#ifdef DEBUG_BUILD

Layer::Layer(std::string layername, bool isRenderAble)
{
    m_layerName = layername;
    m_renderAble = isRenderAble;

    root = new ComponentParent(this);
}

#endif

Layer::~Layer()
{
    delete root;
}

void Layer::update()
{
    onUpdate();
    m_timer.reset();
}

float Layer::getElapsedTime()
{
    return m_timer.getElapsedTimeSeconds();
}