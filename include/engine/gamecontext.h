#ifndef BE_GAMECONTEXT_H
#define BE_GAMECONTEXT_H

namespace be
{

class PlayerController;
class Level;

/**
 * @brief GameContext objects hold all the current game info, playercontroller, level, etc
 * 
 * @note More references will added in the future
 */
class GameContext
{
protected:
    PlayerController *playerController;
    Level *level;

public:
    PlayerController *getPlayerController() { return playerController; }
    Level *getLevel() { return level; }
};

} // namepsace be

#endif // BE_GAMECONTEXT_H