//

#ifndef PACMAN_SCOREBOARD_H
#define PACMAN_SCOREBOARD_H

#include "PMLogic.h"
#include "Pattern/Singleton/Singleton.h"
#include <set>

#define HIGHSCORE_PATH "src/config/highScore.json"

/**
 * @brief A singleton which loads and writes to a file keeping top 5 high scores of all time.
 */
class PMLogic::Scoreboard : public PMLogic::Singleton<PMLogic::Scoreboard> {
protected:
    Scoreboard();

    /**
     * @brief High scores
     */
    std::set<int> highScore;
public:

     /**
      * @brief Returns the 5 highest scores
      * @return 5 highest scores.
      */
     std::array<int, 5> GetHighScore() const;

     /**
      * @brief Add a score to the set of scores
      * @param score The given score.
      */
     void AddScore(const int &score);

     /**
      * @brief Writes the high scores to a file.
      */
     void SaveHighScore() const;
};

#endif // PACMAN_SCOREBOARD_H
