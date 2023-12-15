//

#include "Entity.h"
#include <iostream>

PMLogic::Entity::~Entity() {
    onEntityDestroy->Notify(*onEntityDestroy);
}

PMLogic::Entity::Entity(Coordinate2D::NormalizedCoordinate startPosition, const Coordinate2D::Coordinate &size)
    : position(std::move(startPosition)), size(size),
    onPositionChange(std::make_unique<EntityPositionChangeEvent>(startPosition)),
    onEntityDestroy(std::make_unique<EntityDestroyEvent>()) {}

Coordinate2D::NormalizedCoordinate PMLogic::Entity::GetPosition() const {
    return position;
}

void PMLogic::Entity::SetPosition(const Coordinate2D::NormalizedCoordinate &newPosition) {
    position = newPosition;
    onPositionChange->newPosition = newPosition;
    onPositionChange->Notify(*onPositionChange);
}

Coordinate2D::Coordinate PMLogic::Entity::GetSize() const {
    return size;
}
void PMLogic::Entity::SetOnCollision(const std::shared_ptr<OnCollisionCommand> &onCollisionArg) {
    onCollision = onCollisionArg;
}
