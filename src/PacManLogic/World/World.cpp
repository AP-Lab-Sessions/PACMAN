//

#include "World.h"
#include "Helper/DeltaTime/DeltaTime.h"
#include <fstream>


Coordinate2D::NormalizedCoordinate GetCentered(const Coordinate2D::NormalizedCoordinate &pos,
                                               const Coordinate2D::Coordinate &size, const float &smallFactor) {
    return {pos.GetX()+(size.GetX()/2)-(size.GetX()/(2*smallFactor)), pos.GetY()+(size.GetY()/2)-(size.GetY()/(2*smallFactor))};
}

void PMLogic::World::ImportLevel(const std::string &levelStr) {
    entities.clear();
    std::vector<std::unique_ptr<CollectableEntity>> collectables;
    std::vector<std::shared_ptr<Ghost>> ghosts;

    int width = 0, height=1;

    for (const auto &c : levelStr) {
        if (c == '\n') {
            height++;
        } else {
            width++;
        }
    }
    width = (width / height)+1;


    const Coordinate2D::Coordinate size {
        (Coordinate2D::normalizedMax-Coordinate2D::normalizedMin)/static_cast<float>(width),
        (Coordinate2D::normalizedMax-Coordinate2D::normalizedMin)/static_cast<float>(height)
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
            collectables.push_back(factory->CreateCoin(centeredPosition,smallerSize));
            currentX += size.GetX();
            break;
        }
        case 'f': {
            const float &smallerFactor = 2;
            const Coordinate2D::Coordinate smallerSize = {size.GetX()/smallerFactor, size.GetY()/smallerFactor};
            const Coordinate2D::NormalizedCoordinate centeredPosition {GetCentered(position, size, smallerFactor)};
            collectables.push_back(factory->CreateFruit(centeredPosition, smallerSize));
            currentX += size.GetX();
            break;
        }
        case 'p': {
            const std::shared_ptr<PacMan> pacMan = factory->CreatePacMan(position, {size.GetX(), size.GetY()});
            player = pacMan;
            entities.push_back(pacMan);
            currentX += size.GetX();
            break;
        }
        case 'g': {
            for(int i=0;i<4;i++) ghosts.push_back(factory->CreateGhost(position, {size.GetX(), size.GetY()},
                                                      difficultyFactor));
            currentX += size.GetX();
            break;
        }
        case '#': {
            entities.push_back(factory->CreateWall(position, {size.GetX(), size.GetY()}));
            currentX += size.GetX();
            break;
        }
        default:
            currentX += size.GetX();
            break;
        }
    }

        for (auto& currentCollectable : collectables) {
            for (auto& currentGhost : ghosts) {
                currentCollectable->onEntityCollected->Attach(currentGhost);
            }
            currentCollectable->onEntityCollected->Attach(score);
            entities.push_back(std::move(currentCollectable));
        }
        for (auto& currentGhost : ghosts) {
            currentGhost->onEntityCollected->Attach(score);
            player.lock()->onPositionChange->Attach(currentGhost);
            player.lock()->onEntityDestroy->Attach(currentGhost);
            entities.push_back(currentGhost);
        }
        for (const auto& currentEntity : entities) {
            if (!currentEntity->onCollision)
                currentEntity->SetOnCollision(onCollision);
        }
}

PMLogic::World::World(std::unique_ptr<AbstractFactory> &factoryArg)
    : factory(std::move(factoryArg)), updateVisitor(std::make_shared<UpdateVisitor>()),
    onCollision(std::make_shared<OnCollisionCommand>(destructables)), score(std::make_shared<Score>()),
    difficultyFactor(1.0f) {
    std::ifstream levelFile("src/config/level.txt");
    std::string content{std::istreambuf_iterator<char>(levelFile), std::istreambuf_iterator<char>()};
    levelFile.close();
    ImportLevel(content);
}
void PMLogic::World::DestroyDestructables() {
    for(const auto &currentDestructable : destructables) {
        for(auto &currentEntity : entities) {
            if(currentEntity.get() == &currentDestructable.get()) {
                currentEntity.reset();
            }
        }
        entities.remove(nullptr);
    }
    destructables.clear();
}
void PMLogic::World::Update() {
    std::weak_ptr<PMLogic::Helper::DeltaTime> stopWatch = PMLogic::Helper::DeltaTime::GetInstance();
    stopWatch.lock()->Tick();

    for (const auto &currentEntity: entities) {
        for (const auto &currentEntity2: entities) {
            currentEntity->CollideWith(*currentEntity2);
        }
    }

    DestroyDestructables();

    for(const auto &currentEntity : entities) {
        currentEntity->Accept(updateVisitor);
    }
}

void PMLogic::World::SetPlayerDirection(const DiscreteDirection2D &newDirection) {
    if(!player.expired()) {
        player.lock()->SetDirection(newDirection);
    }
}

int PMLogic::World::GetScore() const {
    return score->GetScore();
}
