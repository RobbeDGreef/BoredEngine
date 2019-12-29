#ifndef BE_PLAYERCONTROLLER_H
#define BE_PLAYERCONTROLLER_H


#include <engine/gameobjects/actor.h>
#include <engine/gameobjects/component.h>

namespace be
{

/**
 * The playercontroller is a special type of actor, it should not hold sprite's and other components directly, 
 * instead it should 'posseses' different actors. The possing makes it easier to switch between different
 * player models. 
 * 
 */
class PlayerController: public Actor
{

protected:
    Actor *PossedActor;

public:
    PlayerController(ComponentParent *parent);
    PlayerController(ComponentParent *parent, Actor *toPossesActor);
    void possess(Actor *);

    /**
     * @brief See actor documentation
     */
    bool addMovement(Vector2 <float> movement) override;
    bool addMovement(float amount, Rotator <float> direction) override;
    bool addMovement(float x, float y) override;
    bool teleport(Vector2 <float> newloc, bool checkCollision=false) override;
    bool teleport(float x, float y, bool checkCollision=false) override;

};


} // namespace be

#endif // BE_PLAYERCONTROLLER_H