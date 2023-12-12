//

#include "World.h"
#include "Helper/StopWatch/StopWatch.h"

bool areOverlapping(const Coordinate2D::NormalizedCoordinate &pos1, const Coordinate2D::Coordinate &size1,
                    const Coordinate2D::NormalizedCoordinate &pos2, const Coordinate2D::Coordinate &size2) {
    return (pos1.GetX() < pos2.GetX()+size2.GetX() && pos1.GetX()+size1.GetX() > pos2.GetX()
    && pos1.GetY() < pos2.GetY()+size2.GetY() && pos1.GetY()+size1.GetY() > pos2.GetY());
}

template<typename EntityType>
void PMLogic::World::CallbackAndPush(const std::shared_ptr<EntityType> &entity,
                                     const std::function<void(const std::weak_ptr<EntityType> &)> &Callback) {
    Callback(entity);
    entities.push_back(entity);
}
PMLogic::World::World(std::unique_ptr<AbstractFactory> &factoryArg)
    : factory(std::move(factoryArg)), updateVisitor(std::make_shared<UpdateVisitor>()) {

    CallbackAndPush<DynamicEntity>(factory->CreatePacMan({0.0f, 0.0f}),
                                   [&](const std::weak_ptr<DynamicEntity> & entity) {
        player = entity.lock();
    });

    entities.push_back(factory->CreateWall({-1.0f, -1.0f}, {2.0f, 0.05f}));
    entities.push_back(factory->CreateWall({-1.0f, -1.0f}, {0.05f, 0.95f}));

    entities.push_back(factory->CreateWall({-1.0f, 0.95f}, {2.0f, 0.05f}));
}
// TODO: separate collision into updatevisitor or command pattern
void PMLogic::World::Update() {
    bool isOverlapping = false;
    for(const auto &currentEntity : entities) {
        if(player.lock() != currentEntity && areOverlapping(player.lock()->GetNextPosition(), player.lock()->GetSize(),
                          currentEntity->GetPosition(), currentEntity->GetSize())) {
            isOverlapping = true;
        }
    }
    if(!isOverlapping)player.lock()->Move();
}

void PMLogic::World::SetPlayerDirection(const DiscreteDirection2D &newDirection) {
    player.lock()->SetDirection(newDirection);
}