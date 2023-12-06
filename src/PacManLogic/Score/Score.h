//

#ifndef PACMAN_SCORE_H
#define PACMAN_SCORE_H

#include "Entity/PacMan/PacMan.h"
#include "Observer/IObserver.h"

// TODO
/**
 * @brief Keeps the score of the current game and at the end gives the score to the Scoreboard to handle it.
 */
class PMLogic::Score : PMLogic::Observer<PacMan> {
protected:
    int currentScore;
public:
    Score();

    void IncreaseScore(const int &amount);
    void DecreaseScore(const int &amount);

    int GetScore() const;

    void Update(const PacMan &pacMan) override;
};

#endif // PACMAN_SCORE_H
