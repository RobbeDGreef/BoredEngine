#ifndef BE_CAMERA_H
#define BE_CAMERA_H

#include <engine/gameobjects/component.h>

#define DEFAULT_CAMERA_DISTANCE 20

namespace be
{

class Camera: public Component
{

private:
    unsigned int m_width;
    unsigned int m_height;
    float m_zoom;

public:
    Camera(ComponentParent *parent, Vector2<float> location, unsigned int width, unsigned int height);
    float getZoom();

    void setZoom(float zoom);
    void setDistance(unsigned int distance);
};

} // namespace be

#endif // BE_CAMERA_H