//

#include "Entity.h"


PMLogic::Entity::Entity(Coordinate2D::NormalizedCoordinate startPosition, const Coordinate2D::Coordinate &size)
    : position(std::move(startPosition)), size(size),
    onEntityDestroy(std::make_unique<EntityDestroyEvent>()),
      onEntityCreate(std::make_unique<EntityCreateEvent>(startPosition, size)) {}

Coordinate2D::NormalizedCoordinate PMLogic::Entity::GetPosition() const {
    return position;
}

Coordinate2D::Coordinate PMLogic::Entity::GetSize() const {
    return size;
}

void PMLogic::Entity::Create() const {
    onEntityCreate->Notify(*onEntityCreate);
}

PMLogic::Entity::~Entity() {
    onEntityDestroy->Notify(*onEntityDestroy);
}