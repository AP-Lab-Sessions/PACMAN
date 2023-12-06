//

#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H

#include "AbstractFactory/AbstractFactory.h"
#include "PacManLogic/IObserver/IObserver.h"
#include <vector>

class EntityFactory : PMLogic::AbstractFactory {
protected:
    const std::weak_ptr<std::vector<std::shared_ptr<PMLogic::IObserver>>> observers;

    template<typename EntityType>
    std::unique_ptr<EntityType> CreateEntity() const;
public:
    explicit EntityFactory(const std::weak_ptr<std::vector<std::shared_ptr<PMLogic::IObserver>>> &observers_ptr);

    std::unique_ptr<PMLogic::Entity> CreatePacMan() const override;

    std::unique_ptr<PMLogic::Entity> CreateGhost() const override;

    std::unique_ptr<PMLogic::Entity> CreateWall() const override;

    std::unique_ptr<PMLogic::Entity> CreateFruit() const override;

    std::unique_ptr<PMLogic::Entity> CreateCoin() const override;
};

#endif // PACMAN_ENTITYFACTORY_H
