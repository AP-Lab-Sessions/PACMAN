//

#include "EntityFactory.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/Wall/Wall.h"

#include "View/EntityView/Coin/CoinView.h"
#include "View/EntityView/DynamicEntityView/Ghost/GhostView.h"
#include "View/EntityView/DynamicEntityView/PacMan/PacManView.h"
#include "View/EntityView/Fruit/FruitView.h"
#include "View/EntityView/Wall/WallView.h"

PMGame::EntityFactory::EntityFactory(std::vector<std::shared_ptr<View::EntityView>>& viewsRef,
                                     const std::weak_ptr<sf::RenderWindow>& window)
    : viewsRef(viewsRef), window(window) {}

std::unique_ptr<PMGame::Logic::PacMan> PMGame::EntityFactory::CreatePacMan(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PMGame::Logic::PacMan> entity{new PMGame::Logic::PacMan(startPosition, size)};
    std::shared_ptr<View::PacManView> view{new View::PacManView(window)};

    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onPositionChange->Attach(view);
    entity->onDirectionChange->Attach(view);

    entity->Create();
    return entity;
}

std::unique_ptr<PMGame::Logic::Coin> PMGame::EntityFactory::CreateCoin(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PMGame::Logic::Coin> entity{new PMGame::Logic::Coin(startPosition, size)};
    std::shared_ptr<View::CoinView> view{new View::CoinView(window)};

    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onEntityCollected->Attach(view);

    entity->Create();
    return entity;
}

std::unique_ptr<PMGame::Logic::Fruit> PMGame::EntityFactory::CreateFruit(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PMGame::Logic::Fruit> entity{new PMGame::Logic::Fruit(startPosition, size)};
    std::shared_ptr<View::FruitView> view{new View::FruitView(window)};

    viewsRef.push_back(view);
    entity->onEntityDestroy->Attach(view);
    entity->onEntityCreate->Attach(view);
    entity->onEntityCollected->Attach(view);

    entity->Create();
    return entity;
}

std::unique_ptr<PMGame::Logic::Ghost> PMGame::EntityFactory::CreateGhost(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size, const float& power, const float& stasisTime) const {
    std::unique_ptr<PMGame::Logic::Ghost> entity{new PMGame::Logic::Ghost(startPosition, size, power, stasisTime)};
    std::shared_ptr<View::GhostView> view{new View::GhostView(window)};

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

std::unique_ptr<PMGame::Logic::Wall> PMGame::EntityFactory::CreateWall(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PMGame::Logic::Wall> entity{new PMGame::Logic::Wall(startPosition, size)};
    std::shared_ptr<View::WallView> view{new View::WallView(window)};

    viewsRef.push_back(view);
    entity->onEntityCreate->Attach(view);
    entity->onEntityDestroy->Attach(view);

    entity->Create();
    return entity;
}
