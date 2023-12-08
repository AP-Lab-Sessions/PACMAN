//

#ifndef PACMAN_SCOREBOARD_H
#define PACMAN_SCOREBOARD_H

#include "PMLogic.h"
#include <memory>
#include <set>

#define HIGHSCORE_PATH "src/json/highScore.json"

/**
 * @brief A singleton which loads and writes to a file keeping top 5 high scores of all time.
 */
class PMLogic::Scoreboard {
private:
    Scoreboard();

    static std::shared_ptr<PMLogic::Scoreboard> instance;
    /**
     * @brief High scores
     */
    std::set<int> highScore;
public:
    /**
     * @brief Make the assignment operator deleted
     */
     void operator=(const PMLogic::Scoreboard &) = delete;

     /**
     * @brief Make the copy constructor deleted
      */
     Scoreboard(PMLogic::Scoreboard &) = delete;

     /**
     * @brief Gets the single instance of the class
     * @return The pointer to the instance
      */
     static std::weak_ptr<PMLogic::Scoreboard> GetInstance();

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
