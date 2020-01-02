/**
 * @file playercontroller.h
 * @author Robbe De Greef (robbedegreef@gmail.com)
 * @brief Implements the playercontroller class
 * @version 0.1
 * @date 2019-12-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BE_PLAYERCONTROLLER_H
#define BE_PLAYERCONTROLLER_H


#include <engine/gameobjects/actor.h>
#include <engine/gameobjects/component.h>
#include <engine/gameobjects/camera.h>

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
    be::Camera *ActiveCamera;
    std::string playerName = "Player";

public:
    PlayerController(ComponentParent *parent);
    PlayerController(ComponentParent *parent, Actor *toPossesActor);
    void possess(Actor *);

    // @fixme: why do we need to put be:: before the camera reference??
    void setActiveCamera(be::Camera*);
    be::Camera *getActiveCamera();
    std::string getName() { return playerName; }

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