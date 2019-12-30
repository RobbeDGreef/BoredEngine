#ifndef BE_PHYSICSSYS_H
#define BE_PHYSICSSYS_H

#include <engine/layer.h>

namespace be
{

class PhysicsSystem: public Layer
{

public:
    PhysicsSystem(ComponentParent *_root): Layer(false, _root) { } 
    void onUpdate() override;

};

} // namespace be

#endif // BE_PHYSICSSYS_H