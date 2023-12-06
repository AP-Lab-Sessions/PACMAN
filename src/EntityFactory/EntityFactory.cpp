//

#include "EntityFactory.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/Wall/Wall.h"

#include "EntityView/PacMan/PacManView.h"
#include "EntityView/Ghost/GhostView.h"
#include "EntityView/Wall/WallView.h"
#include "EntityView/Coin/CoinView.h"
#include "EntityView/Fruit/FruitView.h"

template<typename EntityType>
std::unique_ptr<EntityType> EntityFactory::CreateEntity() const {
    std::unique_ptr<EntityType> entity {new EntityType()};
    std::shared_ptr<PMLogic::IObserver> view{new View<EntityType>()};
    observers.lock()->push_back(view);
    entity->Attach(view);
    return entity;
}

EntityFactory::EntityFactory(const std::weak_ptr<std::vector<std::shared_ptr<PMLogic::IObserver>>>& observers_ptr)
: observers(observers_ptr) {}


std::unique_ptr<PMLogic::Entity> EntityFactory::CreatePacMan() const {
    return CreateEntity<PacMan>();
}

std::unique_ptr<PMLogic::Entity> EntityFactory::CreateCoin() const {
    return CreateEntity<Coin>();
}

std::unique_ptr<PMLogic::Entity> EntityFactory::CreateFruit() const {
    return CreateEntity<Fruit>();
}

std::unique_ptr<PMLogic::Entity> EntityFactory::CreateGhost() const {
    return CreateEntity<Ghost>();
}

std::unique_ptr<PMLogic::Entity> EntityFactory::CreateWall() const {
    return CreateEntity<Wall>();
}
