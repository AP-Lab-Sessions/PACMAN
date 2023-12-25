//

#include "Level.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/Intersection/Intersection.h"
#include "Entity/StaticEntity/Wall/Wall.h"

#include <map>

std::pair<int, int> GetLevelSize(const std::string& levelStrArg) {
    int width{0}, height{1};

    for (const auto& c : levelStrArg) {
        if (c == '\n') {
            height++;
        } else {
            width++;
        }
    }
    if (width % height != 0)
        throw std::runtime_error("All widths and heights of a level must be the same!");
    width = (width / height) + 1;
    return {width, height};
}
std::list<PMGame::Logic::Coordinate2D::DiscreteDirection2D> PMGame::Logic::Level::GetIntersectionDirections(
    const int& x, const int& y) const {
    std::list<PMGame::Logic::Coordinate2D::DiscreteDirection2D> result;
    std::map<std::pair<int, int>, PMGame::Logic::Coordinate2D::DiscreteDirection2D> directionMap{
        {{x - 1, y}, PMGame::Logic::Coordinate2D::Direction_Left},
        {{x + 1, y}, PMGame::Logic::Coordinate2D::Direction_Right},
        {{x, y - 1}, PMGame::Logic::Coordinate2D::Direction_Up},
        {{x, y + 1}, PMGame::Logic::Coordinate2D::Direction_Down}};
    for (const auto& currentElement : directionMap) {
        if (CharIsPath(GetLevelChar(currentElement.first.first, currentElement.first.second)))
            result.push_back(currentElement.second);
    }
    return result;
}
char PMGame::Logic::Level::GetLevelChar(const int& x, const int& y) const {
    int (*generalMod)(const int& a, const int& b) = [](const int& a, const int& b) -> int { return (a % b + b) % b; };
    return levelStr[generalMod(y, levelSize.second) * levelSize.first + generalMod(x, levelSize.first)];
}
bool PMGame::Logic::Level::CharIsPath(const char& c) const { return c != '#' && c != '\n'; }
void PMGame::Logic::Level::AddIntersections(const PMGame::Logic::Coordinate2D::Coordinate& intersectionSize,
                                            PMGame::Logic::Coordinate2D::NormalizedCoordinate currentPos) {
    int x{0}, y{0};
    for (const char& currentChar : levelStr) {
        if (currentChar == '\n') {
            currentPos.SetY(currentPos.GetY() + intersectionSize.GetY());
            currentPos.SetX(PMGame::Logic::Coordinate2D::normalizedMin + intersectionSize.GetX() / 2.0f);
            y++, x = 0;
        } else {
            if (CharIsPath(currentChar)) {
                std::list<PMGame::Logic::Coordinate2D::DiscreteDirection2D> directions;
                const bool hasVerticalPath{CharIsPath(GetLevelChar(x, y - 1)) || CharIsPath(GetLevelChar(x, y + 1))};
                const bool hasHorizontalPath{CharIsPath(GetLevelChar(x - 1, y)) || CharIsPath(GetLevelChar(x + 1, y))};
                if (hasHorizontalPath && hasVerticalPath) {
                    entities.push_back(
                        std::make_unique<Intersection>(currentPos, intersectionSize, GetIntersectionDirections(x, y)));
                }
            }
            currentPos.SetX(currentPos.GetX() + intersectionSize.GetX());
            x++;
        }
    }
}

void PMGame::Logic::Level::Load() {
    std::shared_ptr<PMGame::Logic::AbstractFactory> factoryPtr = factory.lock();
    std::vector<std::unique_ptr<CollectableEntity>> collectables;
    std::vector<std::shared_ptr<Ghost>> ghosts;

    const PMGame::Logic::Coordinate2D::Coordinate size{
        (PMGame::Logic::Coordinate2D::normalizedMax - PMGame::Logic::Coordinate2D::normalizedMin) /
            static_cast<float>(levelSize.first),
        (PMGame::Logic::Coordinate2D::normalizedMax - PMGame::Logic::Coordinate2D::normalizedMin) /
            static_cast<float>(levelSize.second)};
    PMGame::Logic::Coordinate2D::NormalizedCoordinate currentPos{
        PMGame::Logic::Coordinate2D::normalizedMin + (size.GetX() / 2.0f), PMGame::Logic::Coordinate2D::normalizedMin};

    AddIntersections(size, currentPos);

    for (const char& currentChar : levelStr) {
        switch (currentChar) {
        case '\n': {
            currentPos.SetY(currentPos.GetY() + size.GetY());
            currentPos.SetX(PMGame::Logic::Coordinate2D::normalizedMin + size.GetX() / 2.0f);
            break;
        }
        case '.': {
            const float& smallerFactor = 4;
            const PMGame::Logic::Coordinate2D::Coordinate smallerSize = {size.GetX() / smallerFactor,
                                                                         size.GetY() / smallerFactor};
            const PMGame::Logic::Coordinate2D::NormalizedCoordinate centeredPosition{
                GetCenteredShrinked(currentPos, size, smallerFactor)};
            collectables.push_back(factoryPtr->CreateCoin(centeredPosition, smallerSize));
            break;
        }
        case 'f': {
            const float& smallerFactor = 2;
            const PMGame::Logic::Coordinate2D::Coordinate smallerSize = {size.GetX() / smallerFactor,
                                                                         size.GetY() / smallerFactor};
            const PMGame::Logic::Coordinate2D::NormalizedCoordinate centeredPosition{
                GetCenteredShrinked(currentPos, size, smallerFactor)};
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
            for (int i = 0; i < 2; i++)
                ghosts.push_back(factoryPtr->CreateGhost(currentPos, size, difficulty, 0.0f));
            for (int i = 0; i < 2; i++)
                ghosts.push_back(
                    factoryPtr->CreateGhost(currentPos, size, difficulty, 5.0f * static_cast<float>(i + 1)));
            break;
        }
        case '#': {
            entities.push_back(factoryPtr->CreateWall(currentPos, size));
            break;
        }
        case ' ': {
            break;
        }
        default:
            throw std::runtime_error("Symbol "+std::to_string(currentChar)+" not supported in level import\n");
        }
        if (currentChar != '\n')
            currentPos.SetX(currentPos.GetX() + size.GetX());
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
    if(player.expired()) throw std::runtime_error("There is no pacman in level!");
    for (auto& currentGhost : ghosts) {
        currentGhost->onEntityCollected->Attach(score.lock());
        player.lock()->onPositionChange->Attach(currentGhost);
        player.lock()->onEntityDestroy->Attach(currentGhost);
        entities.push_back(currentGhost);
    }
    for (const auto& currentEntity : entities) {
        if (currentEntity->onEntityDestroy->entity.expired())
            currentEntity->onEntityDestroy->entity = currentEntity;
        currentEntity->onEntityDestroy->Attach(shared_from_this());
    }
}

PMGame::Logic::Level::Level(const std::string& levelStr, const std::weak_ptr<PMGame::Logic::AbstractFactory>& factory,
                            const std::weak_ptr<PMGame::Logic::Score>& score, const std::weak_ptr<int>& lives,
                            const float &difficulty)
    : completed(false), levelStr(levelStr), levelSize(GetLevelSize(levelStr)), factory(factory), score(score), lives(lives),
      updateVisitor(std::make_shared<UpdateVisitor>()), difficulty(difficulty), collectablesCount(0) {}

void PMGame::Logic::Level::Restart() {
    for (const auto& currentEntity : entities) {
        currentEntity->Respawn();
    }
}
bool PMGame::Logic::Level::GetIsCompleted() const {
    return completed;
}
void PMGame::Logic::Level::DetectAllCollisions() {
    for (const auto& currentEntity : entities) {
        for (const auto& currentEntity2 : entities) {
            currentEntity->CollideWith(*currentEntity2);
        }
    }
}
void PMGame::Logic::Level::Update() {
    destructables.clear();
    DetectAllCollisions();

    bool pacManDied = false;
    for (const auto& currentDestructable : destructables) {
        if (!currentDestructable.expired()) {
            if (!pacManDied && currentDestructable.lock() == player.lock()) {
                pacManDied = true;
                (*lives.lock())--;
            }
            if (!pacManDied || !(*lives.lock()))
                entities.remove(currentDestructable.lock());
        }
    }

    for (const auto& currentEntity : entities) {
        currentEntity->Accept(updateVisitor);
    }

    if (!collectablesCount) {
        completed = true;
    } else if (pacManDied && *lives.lock()) {
        PMGame::Logic::Helper::TimeManager::GetInstance().lock()->Pause();
        Restart();
    }
}

std::weak_ptr<PMGame::Logic::PacMan> PMGame::Logic::Level::GetPlayer() const { return player; }

void PMGame::Logic::Level::Update(const EntityDestroyEvent& eventData) {
    if (!eventData.entity.expired())
        destructables.emplace_back(eventData.entity);
}

void PMGame::Logic::Level::Update(const EntityCollectedEvent&) { collectablesCount--; }
