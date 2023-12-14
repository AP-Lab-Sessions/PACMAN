//

#include "World.h"
#include "Helper/StopWatch/StopWatch.h"


PMLogic::World::World(std::unique_ptr<AbstractFactory> &factoryArg)
    : factory(std::move(factoryArg)), updateVisitor(std::make_shared<UpdateVisitor>()),
    onCollision(std::make_shared<OnCollisionCommand>(destructables)), score(std::make_shared<Score>()) {

    const std::shared_ptr<DynamicEntity> pacMan = factory->CreatePacMan({0.0f,0.0f});

    player = pacMan;
    entities.push_back(pacMan);

    entities.push_back(factory->CreateGhost({0.0f, -0.5f}));
    entities.push_back(factory->CreateWall({-1.0f, -1.0f}, {2.0f, 0.05f}));

    std::vector<std::unique_ptr<CollectableEntity>> collectables;
    collectables.push_back(factory->CreateFruit({-0.0f, -0.6}));

    for (std::unique_ptr<CollectableEntity> &currentCollectable : collectables) {
        currentCollectable->onEntityCollected->Attach(score);
        entities.push_back(std::move(currentCollectable));
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
        if (currentEntity->GetIsCollider()) {
            for (const auto &currentEntity2: entities) {
                currentEntity->CollideWith(*currentEntity2);
            }
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