//

#ifndef WORLD_H
#define WORLD_H

#include "AbstractFactory/AbstractFactory.h"
#include "Level/Level.h"


#define DEFAULT_LEVEL_PATH "src/config/level.txt"

class PMLogic::World {
private:
protected:
    const std::shared_ptr<AbstractFactory> factory;

    std::shared_ptr<Level> level;

    std::shared_ptr<Score> score;

    std::shared_ptr<int> lives;

    float currentDifficulty;
public:
    explicit World(std::unique_ptr<AbstractFactory> &factory);

    void Update();

    int GetScore() const;

    int GetLives() const;

    void SetPlayerDirection(const DiscreteDirection2D &direction);
};

#endif
