//

#include "EntityFactory.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/Wall/Wall.h"

#include "EntityView/DynamicEntityView/PacMan/PacManView.h"
#include "EntityView/DynamicEntityView/Ghost/GhostView.h"
#include "EntityView/Wall/WallView.h"
#include "EntityView/Coin/CoinView.h"
#include "EntityView/Fruit/FruitView.h"

// TODO: make this neater (much less repetition, much less includes if possible)

template<typename EntityType, typename EntityViewType>
std::unique_ptr<EntityType> EntityFactory::CreateEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                                                        const Coordinate2D::Coordinate &size) const {
    std::unique_ptr<EntityType> entity {new EntityType(startPosition, size)};
    std::shared_ptr<EntityViewType> view{new EntityViewType(window)};

    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);

    entity->Create();
    return entity;
}
template<typename DynamicEntityType, typename DynamicEntityViewType>
std::unique_ptr<DynamicEntityType> EntityFactory::CreateDynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                                                                      const Coordinate2D::Coordinate &size) const {
    std::unique_ptr<DynamicEntityType> entity {new DynamicEntityType(startPosition, size)};
    std::shared_ptr<DynamicEntityViewType> view{new DynamicEntityViewType(window)};


    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onPositionChange->Attach(view);
    entity->onDirectionChange->Attach(view);

    entity->Create();
    return entity;
}

EntityFactory::EntityFactory(std::vector<std::shared_ptr<EntityView>> &viewsRef,
                             const std::weak_ptr<sf::RenderWindow> &window)
: viewsRef(viewsRef), window(window) {}


std::unique_ptr<PacMan> EntityFactory::CreatePacMan(
        const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size
        ) const {
    return CreateDynamicEntity<PacMan, PacManView>(startPosition, size);
}

std::unique_ptr<Coin> EntityFactory::CreateCoin(
        const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size
        ) const {
    return CreateEntity<Coin, CoinView>(startPosition, size);
}

std::unique_ptr<Fruit> EntityFactory::CreateFruit(
        const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size
        ) const {
    auto fruit = CreateEntity<Fruit, FruitView>(startPosition, size);
    return fruit;
}

std::unique_ptr<Ghost> EntityFactory::CreateGhost(
        const Coordinate2D::NormalizedCoordinate &startPosition,
    const Coordinate2D::Coordinate &size, const float &power) const {
    std::unique_ptr<Ghost> entity {new Ghost(startPosition, size, power)};
    std::shared_ptr<GhostView> view{new GhostView(window)};


    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onPositionChange->Attach(view);
    entity->onDirectionChange->Attach(view);
    entity->onModeChange->Attach(view);

    entity->Create();
    return entity;
}

std::unique_ptr<Wall> EntityFactory::CreateWall(
        const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size
) const {
    std::unique_ptr<Wall> entity {new Wall(startPosition, size)};
    std::shared_ptr<WallView> view{new WallView(window)};

    viewsRef.push_back(view);
    entity->onEntityCreate->Attach(view);
    entity->onEntityDestroy->Attach(view);

    entity->Create();
    return entity;
}
