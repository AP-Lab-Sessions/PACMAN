//

#include "DynamicEntity.h"

DynamicEntity::DynamicEntity() : PMLogic::Entity(), currentPosition(startPosition) {}

DynamicEntity::DynamicEntity(const Coordinate2D::NormalizedCoordinate& startPosition)
    : PMLogic::Entity(startPosition), currentPosition(startPosition) {}