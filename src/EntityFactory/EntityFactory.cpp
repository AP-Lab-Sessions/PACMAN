//

#include "EntityFactory.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/Wall/Wall.h"

#include "EntityView/Coin/CoinView.h"
#include "EntityView/DynamicEntityView/Ghost/GhostView.h"
#include "EntityView/DynamicEntityView/PacMan/PacManView.h"
#include "EntityView/Fruit/FruitView.h"
#include "EntityView/Wall/WallView.h"

EntityFactory::EntityFactory(std::vector<std::shared_ptr<EntityView>>& viewsRef,
                             const std::weak_ptr<sf::RenderWindow>& window)
    : viewsRef(viewsRef), window(window) {}

std::unique_ptr<PacMan> EntityFactory::CreatePacMan(const Coordinate2D::NormalizedCoordinate& startPosition,
                                                    const Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PacMan> entity{new PacMan(startPosition, size)};
    std::shared_ptr<PacManView> view{new PacManView(window)};

    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onPositionChange->Attach(view);
    entity->onDirectionChange->Attach(view);

    entity->Create();
    return entity;
}

std::unique_ptr<Coin> EntityFactory::CreateCoin(const Coordinate2D::NormalizedCoordinate& startPosition,
                                                const Coordinate2D::Coordinate& size) const {
    std::unique_ptr<Coin> entity{new Coin(startPosition, size)};
    std::shared_ptr<CoinView> view{new CoinView(window)};

    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onEntityCollected->Attach(view);

    entity->Create();
    return entity;
}

std::unique_ptr<Fruit> EntityFactory::CreateFruit(const Coordinate2D::NormalizedCoordinate& startPosition,
                                                  const Coordinate2D::Coordinate& size) const {
    std::unique_ptr<Fruit> entity{new Fruit(startPosition, size)};
    std::shared_ptr<FruitView> view{new FruitView(window)};

    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onEntityCollected->Attach(view);

    entity->Create();
    return entity;
}

std::unique_ptr<Ghost> EntityFactory::CreateGhost(const Coordinate2D::NormalizedCoordinate& startPosition,
                                                  const Coordinate2D::Coordinate& size, const float& power,
                                                  const float& stasisTime) const {
    std::unique_ptr<Ghost> entity{new Ghost(startPosition, size, power, stasisTime)};
    std::shared_ptr<GhostView> view{new GhostView(window)};

    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onPositionChange->Attach(view);
    entity->onDirectionChange->Attach(view);
    entity->onModeChange->Attach(view);
    entity->onEntityCollected->Attach(view);

    entity->Create();
    return entity;
}

std::unique_ptr<Wall> EntityFactory::CreateWall(const Coordinate2D::NormalizedCoordinate& startPosition,
                                                const Coordinate2D::Coordinate& size) const {
    std::unique_ptr<Wall> entity{new Wall(startPosition, size)};
    std::shared_ptr<WallView> view{new WallView(window)};

    viewsRef.push_back(view);
    entity->onEntityCreate->Attach(view);
    entity->onEntityDestroy->Attach(view);

    entity->Create();
    return entity;
}
