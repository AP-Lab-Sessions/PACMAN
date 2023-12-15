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


template<typename EntityType, typename EntityViewType>
std::unique_ptr<EntityType> EntityFactory::CreateEntity(const Coordinate2D::NormalizedCoordinate &startPosition) const {
    std::unique_ptr<EntityType> entity {new EntityType(startPosition)};
    std::shared_ptr<EntityViewType> view{new EntityViewType(*entity, window)};

    std::function<void()> callback = [view](){view->Render();};

    renderCallbacks.lock()->push_back(callback);
    entity->onPositionChange->Attach(view);
    entity->onEntityDestroy->Attach(view);
    return entity;
}

EntityFactory::EntityFactory(const std::weak_ptr<std::vector<std::function<void()>>>& callbacks,
                             const std::weak_ptr<sf::RenderWindow> &window)
: renderCallbacks(callbacks), window(window) {}


std::unique_ptr<DynamicEntity> EntityFactory::CreatePacMan(
        const Coordinate2D::NormalizedCoordinate &startPosition
        ) const {
    auto pacMan = CreateEntity<PacMan, PacManView>(startPosition);
    return pacMan;
}

std::unique_ptr<CollectableEntity> EntityFactory::CreateCoin(
        const Coordinate2D::NormalizedCoordinate &startPosition
        ) const {
    return CreateEntity<Coin, CoinView>(startPosition);
}

std::unique_ptr<CollectableEntity> EntityFactory::CreateFruit(
        const Coordinate2D::NormalizedCoordinate &startPosition
        ) const {
    return CreateEntity<Fruit, FruitView>(startPosition);
}

std::unique_ptr<AutomaticEntity> EntityFactory::CreateGhost(
        const Coordinate2D::NormalizedCoordinate &startPosition) const {
    return CreateEntity<Ghost, GhostView>(startPosition);
}

std::unique_ptr<StaticEntity> EntityFactory::CreateWall(
        const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size
) const {
    std::unique_ptr<Wall> entity {new Wall(startPosition, size)};
    std::shared_ptr<WallView> view{new WallView(*entity, window)};

    std::function<void()> callback = [view](){view->Render();};
    renderCallbacks.lock()->push_back(callback);
    entity->onPositionChange->Attach(view);
    entity->onEntityDestroy->Attach(view);
    return entity;
}
