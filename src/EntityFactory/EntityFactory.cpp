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

template <typename EntityViewType, typename... EventType>
void PMGame::EntityFactory::AttachView(const std::unique_ptr<EventType>&... event) const {
    std::shared_ptr<EntityViewType> entityView{new EntityViewType(window)};
    viewsRef.push_back(entityView);
    ((event->Attach(entityView)), ...);
}

std::unique_ptr<PMGame::Logic::PacMan> PMGame::EntityFactory::CreatePacMan(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PMGame::Logic::PacMan> entity{new PMGame::Logic::PacMan(startPosition, size)};

    AttachView<PMGame::View::PacManView>(entity->onEntityCreate, entity->onEntityDestroy, entity->onPositionChange,
                                         entity->onDirectionChange);

    entity->Create();
    return entity;
}

std::unique_ptr<PMGame::Logic::Coin> PMGame::EntityFactory::CreateCoin(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PMGame::Logic::Coin> entity{new PMGame::Logic::Coin(startPosition, size)};

    AttachView<PMGame::View::CoinView>(entity->onEntityCreate, entity->onEntityDestroy, entity->onEntityCollected);

    entity->Create();
    return entity;
}

std::unique_ptr<PMGame::Logic::Fruit> PMGame::EntityFactory::CreateFruit(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PMGame::Logic::Fruit> entity{new PMGame::Logic::Fruit(startPosition, size)};

    AttachView<PMGame::View::FruitView>(entity->onEntityCreate, entity->onEntityDestroy, entity->onEntityCollected);

    entity->Create();
    return entity;
}

std::unique_ptr<PMGame::Logic::Ghost> PMGame::EntityFactory::CreateGhost(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size, const float& power, const float& stasisTime) const {
    std::unique_ptr<PMGame::Logic::Ghost> entity{new PMGame::Logic::Ghost(startPosition, size, power, stasisTime)};

    AttachView<PMGame::View::GhostView>(entity->onEntityCreate, entity->onEntityDestroy, entity->onPositionChange,
                                        entity->onDirectionChange, entity->onEntityCollected, entity->onModeChange);

    entity->Create();
    return entity;
}

std::unique_ptr<PMGame::Logic::Wall> PMGame::EntityFactory::CreateWall(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
    const PMGame::Logic::Coordinate2D::Coordinate& size) const {
    std::unique_ptr<PMGame::Logic::Wall> entity{new PMGame::Logic::Wall(startPosition, size)};

    AttachView<PMGame::View::WallView>(entity->onEntityCreate, entity->onEntityDestroy);

    entity->Create();
    return entity;
}
