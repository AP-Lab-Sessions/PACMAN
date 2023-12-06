//

#include "DynamicEntity.h"

DynamicEntity::DynamicEntity() : PMLogic::Entity(), currentPosition(startPosition), isAlive(true),
                                 currentDirection(Direction_Left)  {}

DynamicEntity::DynamicEntity(const Coordinate2D::NormalizedCoordinate& startPosition)
    : PMLogic::Entity(startPosition), currentPosition(startPosition), isAlive(true), currentDirection(Direction_Left) {}

Coordinate2D::NormalizedCoordinate DynamicEntity::GetCurrentPosition() const {
    return currentPosition;
}

void DynamicEntity::SetCurrentPosition(const Coordinate2D::NormalizedCoordinate& newCurrentPosition) {
    currentPosition = newCurrentPosition;
}

