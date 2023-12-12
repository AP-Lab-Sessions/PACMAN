//

#ifndef WORLD_H
#define WORLD_H

#include "PMLogic.h"
#include "AbstractFactory/AbstractFactory.h"
#include "Entity/Entity.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "UpdateVisitor/UpdateVisitor.h"

#include <memory>
#include <list>
#include <functional>

class PMLogic::World {
protected:
    const std::unique_ptr<AbstractFactory> factory;

    std::weak_ptr<DynamicEntity> player;

    std::list<std::shared_ptr<PMLogic::Entity>> entities;
    std::shared_ptr<UpdateVisitor> updateVisitor;

    template<typename EntityType>
    void CallbackAndPush(const std::shared_ptr<EntityType> &entity,
                        const std::function<void(const std::weak_ptr<EntityType> &)> &);

public:
    explicit World(std::unique_ptr<AbstractFactory> &factory);

    void Update();

    void SetPlayerDirection(const DiscreteDirection2D &newDirection);
};

#endif
