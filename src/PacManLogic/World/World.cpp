//

#include "World.h"
#include "Helper/StopWatch/StopWatch.h"


PMLogic::World::World(std::unique_ptr<AbstractFactory> &factoryArg)
    : factory(std::move(factoryArg)), updateVisitor(std::make_shared<UpdateVisitor>()),
    onCollision(std::make_shared<OnCollisionCommand>(destructables)), score(std::make_shared<Score>()) {

    std::vector<std::unique_ptr<CollectableEntity>> collectables;
    std::vector<std::shared_ptr<Ghost>> ghosts;

    const float thickness = 0.05f;

    const std::shared_ptr<PacMan> pacMan = factory->CreatePacMan({0.0f,-thickness});

    player = pacMan;
    entities.push_back(pacMan);

    ghosts.push_back(factory->CreateGhost({0.0f, -0.5f}));

    entities.push_back(factory->CreateWall({-0.9f, -0.9f}, {1.8f, thickness}));
    entities.push_back(factory->CreateWall({-0.9f, -0.9f}, {thickness, 1.8f}));

    entities.push_back(factory->CreateWall({-0.9f, 0.9f-thickness}, {1.8f, thickness}));
    entities.push_back(factory->CreateWall({0.9f-thickness, -0.9f}, {thickness, 1.8f}));

    entities.push_back(factory->CreateWall({-0.25f, -0.1f}, {0.5f, thickness}));
    entities.push_back(factory->CreateWall({-0.25f, thickness}, {0.5f, thickness}));

    collectables.push_back(factory->CreateFruit({-0.0f, -0.6f}));
    collectables.push_back(factory->CreateCoin({-0.1f, -0.5f}));

    for (auto &currentCollectable : collectables) {
        for(auto &currentGhost : ghosts) {
            currentCollectable->onEntityCollected->Attach(currentGhost);
        }
        currentCollectable->onEntityCollected->Attach(score);
        entities.push_back(std::move(currentCollectable));
    }
    for(auto &currentGhost : ghosts) {
        pacMan->onPositionChange->Attach(currentGhost);
        pacMan->onEntityDestroy->Attach(currentGhost);
        entities.push_back(currentGhost);
    }
    for (const auto &currentEntity: entities) {
        if(!currentEntity->onCollision) currentEntity->SetOnCollision(onCollision);
    }
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
    std::weak_ptr<PMLogic::Helper::StopWatch> stopWatch = PMLogic::Helper::StopWatch::GetInstance();
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