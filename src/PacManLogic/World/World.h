//

#ifndef WORLD_H
#define WORLD_H

#include "PMLogic.h"
#include "AbstractFactory/AbstractFactory.h"
#include "UpdateVisitor/UpdateVisitor.h"
#include "Score/Score.h"
#include "Events/EntityEvent/EntityDestroyEvent.h"

#include <functional>
#include <list>

class PMLogic::World {
private:
    std::vector<std::reference_wrapper<const PMLogic::Entity>> destructables;
protected:
    const std::unique_ptr<AbstractFactory> factory;

    std::list<std::shared_ptr<PMLogic::Entity>> entities;

    std::weak_ptr<DynamicEntity> player;

    std::shared_ptr<UpdateVisitor> updateVisitor;

    std::shared_ptr<OnCollisionCommand> onCollision;

    std::shared_ptr<Score> score;

    float difficultyFactor;

    void DestroyDestructables();

public:
    void ImportLevel(const std::string &levelStr);

    explicit World(std::unique_ptr<AbstractFactory> &factory);

    void Update();

    int GetScore() const;

    void SetPlayerDirection(const DiscreteDirection2D &newDirection);
};

#endif
