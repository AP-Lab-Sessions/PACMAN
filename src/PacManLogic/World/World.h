//

#ifndef WORLD_H
#define WORLD_H

#include "Pattern/AbstractFactory/AbstractFactory.h"
#include "Level/Level.h"


#define DEFAULT_LEVEL_PATH "src/config/level.txt"

class PMLogic::World {
private:
protected:
    const std::shared_ptr<AbstractFactory> factory;

    std::shared_ptr<Level> level;

    std::shared_ptr<Score> score;

    std::shared_ptr<int> lives;
public:
    explicit World(std::unique_ptr<AbstractFactory> &factory);

    void Update();

    int GetScore() const;

    int GetLives() const;

    void SetPlayerDirection(const Coordinate2D::DiscreteDirection2D &direction);
};

#endif
