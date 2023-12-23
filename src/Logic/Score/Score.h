//

#ifndef PACMAN_SCORE_H
#define PACMAN_SCORE_H

#include "Events/EntityEvent/EntityCollectedEvent.h"
#include "Helper/TimeManager/TimeManager.h"
#include "Pattern/Observer/EventListener/IEventListener.h"

namespace PMGame::Logic {
/**
 * @brief Current score of the game.
 */
class Score : public IEventListener<EntityCollectedEvent> {
private:
    /**
     * @brief Timer used to decrease the score over time.
     */
    std::shared_ptr<Helper::Timer> scoreTimer;
    /**
     * @brief Stopwatch used to determine the duration of the interval two collectable entities were collected
     */
    std::shared_ptr<Helper::StopWatch> stopWatch;

protected:
    /**
     * @brief The current score.
     */
    int currentScore;

    /**
     * @brief Starts the timed decrease of current score.
     */
    void StartTimedDecrease();

public:
    Score();
    ~Score() override;

    /**
     * @brief Increases the score by a certain amount
     * @param amount
     */
    void IncreaseScore(const int& amount);
    /**
     * @brief Decreases the score by a certain amount
     * @param amount
     */
    void DecreaseScore(const int& amount);

    /**
     * @brief Gets the current score.
     * @return The current score.
     */
    int GetScore() const;

    /**
     * @brief Called when pacman collected a collectable entity or ate a ghost.
     * @param eventData Information about what's been collected and the reward.
     */
    void Update(const EntityCollectedEvent& eventData) override;
};
} // namespace PMGame::Logic

#endif // PACMAN_SCORE_H
