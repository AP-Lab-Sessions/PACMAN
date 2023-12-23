//

#include "Level.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include "Entity/StaticEntity/Intersection/Intersection.h"

#include <map>

Coordinate2D::NormalizedCoordinate GetCentered(const Coordinate2D::NormalizedCoordinate &pos,
                                               const Coordinate2D::Coordinate &size, const float &smallFactor) {
    return {pos.GetX()+(size.GetX()/2)-(size.GetX()/(2*smallFactor)), pos.GetY()+(size.GetY()/2)-(size.GetY()/(2*smallFactor))};
}
std::pair<int, int> GetLevelSize(const std::string &levelStrArg) {
    int width {0}, height{1};

    for (const auto &c : levelStrArg) {
        if (c == '\n') {
            height++;
        } else {
            width++;
        }
    }
    if(width % height != 0) throw std::runtime_error("All widths and heights of a level must be the same!");
    width = (width / height)+1;
    return {width, height};
}
std::list<Coordinate2D::DiscreteDirection2D> Level::GetIntersectionDirections(const int& x, const int& y) const {
    std::list<Coordinate2D::DiscreteDirection2D> result;
    std::map<std::pair<int, int>, Coordinate2D::DiscreteDirection2D> directionMap {
        {{x-1, y}, Coordinate2D::Direction_Left},
        {{x+1, y}, Coordinate2D::Direction_Right},
        {{x, y-1}, Coordinate2D::Direction_Up},
        {{x, y+1}, Coordinate2D::Direction_Down}
    };
    for(const auto &currentElement : directionMap) {
        if(CharIsPath(GetLevelChar(currentElement.first.first, currentElement.first.second)))
            result.push_back(currentElement.second);
    }
    return result;
}
char Level::GetLevelChar(const int& x, const int& y) const {
    int(*generalMod)(const int &a, const int &b) = [](const int &a, const int &b) -> int {return (a % b + b) % b;};
    return levelStr[generalMod(y, levelSize.second)*levelSize.first+generalMod(x, levelSize.first)];
}
bool Level::CharIsPath(const char& c) const {
    return c != '#' && c != '\n';
}
void Level::AddIntersections(const Coordinate2D::Coordinate &intersectionSize,
                             Coordinate2D::NormalizedCoordinate currentPos) {
    int x{0}, y{0};
    for(const char& currentChar : levelStr) {
        if(currentChar == '\n') {
            currentPos.SetY(currentPos.GetY()+intersectionSize.GetY());
            currentPos.SetX(Coordinate2D::normalizedMin+intersectionSize.GetX() / 2.0f);
            y++, x=0;
        }
        else {
            if(CharIsPath(currentChar)) {
                std::list<Coordinate2D::DiscreteDirection2D> directions;
                const bool hasVerticalPath {CharIsPath(GetLevelChar(x, y-1)) || CharIsPath(GetLevelChar(x, y+1))};
                const bool hasHorizontalPath {CharIsPath(GetLevelChar(x-1, y)) || CharIsPath(GetLevelChar(x+1, y))};
                if(hasHorizontalPath && hasVerticalPath) {
                    entities.push_back(
                        std::make_unique<Intersection>(currentPos, intersectionSize, GetIntersectionDirections(x, y)));
                }
            }
            currentPos.SetX(currentPos.GetX()+intersectionSize.GetX());
            x++;
        }
    }
}

void Level::Load() {
    std::shared_ptr<PMLogic::AbstractFactory> factoryPtr = factory.lock();
    std::vector<std::unique_ptr<CollectableEntity>> collectables;
    std::vector<std::shared_ptr<Ghost>> ghosts;

    const Coordinate2D::Coordinate size {
        (Coordinate2D::normalizedMax-Coordinate2D::normalizedMin)/static_cast<float>(levelSize.first),
        (Coordinate2D::normalizedMax-Coordinate2D::normalizedMin)/static_cast<float>(levelSize.second)
    };
    Coordinate2D::NormalizedCoordinate currentPos
        {Coordinate2D::normalizedMin+(size.GetX() / 2.0f),  Coordinate2D::normalizedMin};

    AddIntersections(size, currentPos);

    for (const char& currentChar : levelStr) {
        switch (currentChar) {
        case '\n': {
            currentPos.SetY(currentPos.GetY()+size.GetY());
            currentPos.SetX(Coordinate2D::normalizedMin+size.GetX() / 2.0f);
            break;
        }
        case '.': {
            const float &smallerFactor = 4;
            const Coordinate2D::Coordinate smallerSize = {size.GetX()/smallerFactor, size.GetY()/smallerFactor};
            const Coordinate2D::NormalizedCoordinate centeredPosition {GetCentered(currentPos, size, smallerFactor)};
            collectables.push_back(factoryPtr->CreateCoin(centeredPosition,smallerSize));
            break;
        }
        case 'f': {
            const float &smallerFactor = 2;
            const Coordinate2D::Coordinate smallerSize = {size.GetX()/smallerFactor, size.GetY()/smallerFactor};
            const Coordinate2D::NormalizedCoordinate centeredPosition {GetCentered(currentPos, size, smallerFactor)};
            collectables.push_back(factoryPtr->CreateFruit(centeredPosition, smallerSize));
            break;
        }
        case 'p': {
            const std::shared_ptr<PacMan> pacMan = factoryPtr->CreatePacMan(currentPos, size);
            player = pacMan;
            entities.push_back(pacMan);
            break;
        }
        case 'g': {
            for(int i=0;i<2;i++)
                ghosts.push_back(factoryPtr->CreateGhost(currentPos, size, currentDifficulty, 0.0f));
            for(int i=0;i<2;i++)
                ghosts.push_back(factoryPtr->CreateGhost(currentPos, size, currentDifficulty,
                                                         5.0f*static_cast<float>(i+1)));
            break;
        }
        case '#': {
            entities.push_back(factoryPtr->CreateWall(currentPos, size));
            break;
        }
        default:
            break;
        }
        if(currentChar != '\n') currentPos.SetX(currentPos.GetX()+size.GetX());
    }

    for (auto& currentCollectable : collectables) {
        for (auto& currentGhost : ghosts) {
            currentCollectable->onEntityCollected->Attach(currentGhost);
        }
        collectablesCount++;
        currentCollectable->onEntityCollected->Attach(score.lock());
        currentCollectable->onEntityCollected->Attach(shared_from_this());
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

Level::Level(const std::string &levelStr, const std::weak_ptr<PMLogic::AbstractFactory> &factory,
             const std::weak_ptr<PMLogic::Score> &score, const std::weak_ptr<int> &lives)
    : levelStr(levelStr), levelSize(GetLevelSize(levelStr)), factory(factory), score(score), lives(lives),
      updateVisitor(std::make_shared<UpdateVisitor>()), currentDifficulty(1.0f), collectablesCount(0)
{}

void Level::Restart() {
    for (const auto& currentEntity : entities) {
        currentEntity->Respawn();
    }
}

void Level::DetectAllCollisions() {
    for (const auto &currentEntity: entities) {
        for (const auto &currentEntity2: entities) {
            currentEntity->CollideWith(*currentEntity2);
        }
    }
}
void Level::GoNextLevel() {
    PMLogic::Helper::DeltaTime::GetInstance().lock()->Pause();
    entities.clear();
    currentDifficulty *= 1.25;
    Load();
}
void Level::Update() {
    destructables.clear();
    DetectAllCollisions();

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

    if(!collectablesCount) {
        GoNextLevel();
    }
    else if(pacManDied && *lives.lock()) {
        PMLogic::Helper::DeltaTime::GetInstance().lock()->Pause();
        Restart();
    }
}


std::weak_ptr<PacMan> Level::GetPlayer() const {
        return player;
}

void Level::Update(const EntityDestroyEvent& eventData) {
        if(!eventData.entity.expired()) destructables.emplace_back(eventData.entity);
}

void Level::Update(const EntityCollectedEvent&) {
        collectablesCount--;
}

