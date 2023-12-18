//

#include "Level.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/Wall/Wall.h"

Coordinate2D::NormalizedCoordinate GetCentered(const Coordinate2D::NormalizedCoordinate &pos,
                                               const Coordinate2D::Coordinate &size, const float &smallFactor) {
    return {pos.GetX()+(size.GetX()/2)-(size.GetX()/(2*smallFactor)), pos.GetY()+(size.GetY()/2)-(size.GetY()/(2*smallFactor))};
}
Coordinate2D::Coordinate GetLevelSize(const std::string &levelStrArg) {
    float width = 0, height=1;

    for (const auto &c : levelStrArg) {
        if (c == '\n') {
            height++;
        } else {
            width++;
        }
    }
    width = (width / height)+1;
    return {width, height};
}
void Level::Load() {
    std::shared_ptr<PMLogic::AbstractFactory> factoryPtr = factory.lock();
    std::vector<std::unique_ptr<CollectableEntity>> collectables;
    std::vector<std::shared_ptr<Ghost>> ghosts;

    const Coordinate2D::Coordinate size {
        (Coordinate2D::normalizedMax-Coordinate2D::normalizedMin)/levelSize.GetX(),
        (Coordinate2D::normalizedMax-Coordinate2D::normalizedMin)/levelSize.GetY()
    };

    float currentX = Coordinate2D::normalizedMin+(size.GetX() / 2.0f),
          currentY = Coordinate2D::normalizedMin;
    for (const char& currentChar : levelStr) {
        const Coordinate2D::NormalizedCoordinate position{(currentX),(currentY)};
        switch (currentChar) {
        case '\n': {
            currentY += size.GetY();
            currentX = Coordinate2D::normalizedMin+size.GetX() / 2.0f;
            break;
        }
        case '.': {
            const float &smallerFactor = 4;
            const Coordinate2D::Coordinate smallerSize = {size.GetX()/smallerFactor, size.GetY()/smallerFactor};
            const Coordinate2D::NormalizedCoordinate centeredPosition {GetCentered(position, size, smallerFactor)};
            collectables.push_back(factoryPtr->CreateCoin(centeredPosition,smallerSize));
            break;
        }
        case 'f': {
            const float &smallerFactor = 2;
            const Coordinate2D::Coordinate smallerSize = {size.GetX()/smallerFactor, size.GetY()/smallerFactor};
            const Coordinate2D::NormalizedCoordinate centeredPosition {GetCentered(position, size, smallerFactor)};
            collectables.push_back(factoryPtr->CreateFruit(centeredPosition, smallerSize));
            break;
        }
        case 'p': {
            const std::shared_ptr<PacMan> pacMan = factoryPtr->CreatePacMan(position, {size.GetX()/1.05f, size.GetY()/1.05f});
            player = pacMan;
            entities.push_back(pacMan);
            break;
        }
        case 'g': {
            for(int i=0;i<4;i++) ghosts.push_back(factoryPtr->CreateGhost(position, {size.GetX()/1.1f, size.GetY()/1.1f},
                                                         difficultyFactor));
            break;
        }
        case '#': {
            entities.push_back(factoryPtr->CreateWall(position, {size.GetX(), size.GetY()}));
            break;
        }
        default:
            break;
        }
        if(currentChar != '\n') currentX += size.GetX();
    }

    for (auto& currentCollectable : collectables) {
        for (auto& currentGhost : ghosts) {
            currentCollectable->onEntityCollected->Attach(currentGhost);
        }
        currentCollectable->onEntityCollected->Attach(score.lock());
        entities.push_back(std::move(currentCollectable));
    }
    for (auto& currentGhost : ghosts) {
        currentGhost->onEntityCollected->Attach(score.lock());
        player.lock()->onPositionChange->Attach(currentGhost);
        player.lock()->onEntityDestroy->Attach(currentGhost);
        entities.push_back(currentGhost);
    }
    for (const auto& currentEntity : entities) {
        if(currentEntity->onEntityDestroy->entity.expired()) currentEntity->onEntityDestroy->entity = currentEntity;
        currentEntity->onEntityDestroy->Attach(shared_from_this());
    }
}
Coordinate2D::Coordinate Level::GetSize() const {
    return levelSize;
}

Level::Level(const std::string &levelStr, const std::weak_ptr<PMLogic::AbstractFactory> &factory,
             const std::weak_ptr<PMLogic::Score> &score, const std::weak_ptr<int> &lives,
             const float &difficulty)
    : levelStr(levelStr), levelSize(GetLevelSize(levelStr)), factory(factory), score(score), lives(lives),
      updateVisitor(std::make_shared<UpdateVisitor>()),
      difficultyFactor(difficulty)
{}

void Level::Restart() {
    for (const auto& currentEntity : entities) {
        currentEntity->Respawn();
    }
}
void Level::Update() {
    destructables.clear();
    for (const auto &currentEntity: entities) {
        for (const auto &currentEntity2: entities) {
            currentEntity->CollideWith(*currentEntity2);
        }
    }

    bool pacManDied = false;
    for (const auto &currentDestructable : destructables) {
        if(!currentDestructable.expired()) {
            if(!pacManDied && currentDestructable.lock() == player.lock()) {
                pacManDied = true;
                (*lives.lock())--;
            }
            if(!pacManDied || !(*lives.lock())) entities.remove(currentDestructable.lock());
        }
    }

    for(const auto &currentEntity : entities) {
        currentEntity->Accept(updateVisitor);
    }

    if(pacManDied && *lives.lock()) Restart();
}


std::weak_ptr<PacMan> Level::GetPlayer() const {
        return player;
}

void Level::Update(const EntityDestroyEvent& eventData) {
        destructables.emplace_back(eventData.entity);
}

