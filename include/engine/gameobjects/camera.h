#ifndef BE_CAMERA_H
#define BE_CAMERA_H

#include <engine/gameobjects/component.h>

namespace be
{

class Camera: public Component
{

private:
    unsigned int m_width;
    unsigned int m_height;

public:
    Camera(ComponentParent *parent, Vector2<float> location, unsigned int width, unsigned int height);
};

} // namespace be

#endif // BE_CAMERA_H