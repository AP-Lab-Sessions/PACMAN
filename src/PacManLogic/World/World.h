//

#ifndef WORLD_H
#define WORLD_H

#include "Level/Level.h"
#include "Pattern/AbstractFactory/AbstractFactory.h"

#define DEFAULT_LEVEL_PATH "src/config/level.txt"

/**
 * @brief The world that creates and manages the current level, score, and number of lives.
 */
class PMLogic::World {
protected:
    /**
     * @brief Entity factory
     */
    const std::shared_ptr<AbstractFactory> factory;

    /**
     * @brief Game level
     */
    std::shared_ptr<Level> level;

    /**
     * @brief Current score
     */
    std::shared_ptr<Score> score;

    /**
     * @brief Number of lives.
     */
    std::shared_ptr<int> lives;

public:
    /**
     *
     * @param factory Entity factory
     */
    explicit World(std::unique_ptr<AbstractFactory>& factory);

    /**
     * @brief Updates the world by also updating the level.
     */
    void Update();

    /**
     * @brief Gets the current score.
     * @return The current score.
     */
    int GetScore() const;

    /**
     * @brief Gets number of lives.
     * @return Number of lives.
     */
    int GetLives() const;

    /**
     * @brief Sets the current direction of the player entity (PacMan)
     * @param direction
     */
    void SetPlayerDirection(const Coordinate2D::DiscreteDirection2D& direction);
};

#endif
