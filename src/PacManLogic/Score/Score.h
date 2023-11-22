//

#ifndef PACMAN_SCORE_H
#define PACMAN_SCORE_H

#include "Observer/Observer.h"
#include "Entity/PacMan/PacMan.h"

/**
 * @brief Keeps the score of the current game and at the end gives the score to the Scoreboard to handle it.
 */
class Score : PMLogic::Observer<PacMan> {
public:

};

#endif // PACMAN_SCORE_H
