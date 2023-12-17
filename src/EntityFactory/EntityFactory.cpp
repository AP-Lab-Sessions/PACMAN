//

#include "EntityFactory.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/Wall/Wall.h"

#include "EntityView/PacMan/PacManView.h"
#include "EntityView/Ghost/GhostView.h"
#include "EntityView/Wall/WallView.h"
#include "EntityView/Coin/CoinView.h"
#include "EntityView/Fruit/FruitView.h"

// TODO: make this neater (much less repetition, much less includes if possible)

template<typename EntityType, typename EntityViewType>
std::unique_ptr<EntityType> EntityFactory::CreateEntity(const Coordinate2D::NormalizedCoordinate &startPosition) const {
    std::unique_ptr<EntityType> entity {new EntityType(startPosition)};
    std::shared_ptr<EntityViewType> view{new EntityViewType(window)};

    std::function<void()> callback = [view](){view->Render();};

    renderCallbacks.lock()->push_back(callback);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);

    entity->Create();
    return entity;
}
template<typename DynamicEntityType, typename DynamicEntityViewType>
std::unique_ptr<DynamicEntityType> EntityFactory::CreateDynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition) const {
    std::unique_ptr<DynamicEntityType> entity {new DynamicEntityType(startPosition)};
    std::shared_ptr<DynamicEntityViewType> view{new DynamicEntityViewType(window)};

    std::function<void()> callback = [view](){view->Render();};

    renderCallbacks.lock()->push_back(callback);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onPositionChange->Attach(view);
    entity->onDirectionChange->Attach(view);

    entity->Create();
    return entity;
}

EntityFactory::EntityFactory(const std::weak_ptr<std::vector<std::function<void()>>>& callbacks,
                             const std::weak_ptr<sf::RenderWindow> &window)
: renderCallbacks(callbacks), window(window) {}


std::unique_ptr<PacMan> EntityFactory::CreatePacMan(
        const Coordinate2D::NormalizedCoordinate &startPosition
        ) const {
    return CreateDynamicEntity<PacMan, PacManView>(startPosition);
}

std::unique_ptr<Coin> EntityFactory::CreateCoin(
        const Coordinate2D::NormalizedCoordinate &startPosition
        ) const {
    return CreateEntity<Coin, CoinView>(startPosition);
}

std::unique_ptr<Fruit> EntityFactory::CreateFruit(
        const Coordinate2D::NormalizedCoordinate &startPosition
        ) const {
    auto fruit = CreateEntity<Fruit, FruitView>(startPosition);
    return fruit;
}

std::unique_ptr<Ghost> EntityFactory::CreateGhost(
        const Coordinate2D::NormalizedCoordinate &startPosition) const {
    std::unique_ptr<Ghost> entity {new Ghost(startPosition)};
    std::shared_ptr<GhostView> view{new GhostView(window)};

    std::function<void()> callback = [view](){view->Render();};

    renderCallbacks.lock()->push_back(callback);
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

    std::function<void()> callback = [view](){view->Render();};
    renderCallbacks.lock()->push_back(callback);
    entity->onEntityCreate->Attach(view);
    entity->onEntityDestroy->Attach(view);

    entity->Create();
    return entity;
}
