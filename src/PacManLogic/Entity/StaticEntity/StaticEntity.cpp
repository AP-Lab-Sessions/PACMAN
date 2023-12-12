//

#include "StaticEntity.h"

StaticEntity::StaticEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                           const Coordinate2D::Coordinate &size,
                           const bool& isCollectable, const bool& isCollider)
    : PMLogic::Entity(startPosition, size), isCollectable(isCollectable), isCollider(isCollider) {}

bool StaticEntity::GetIsCollectable() const {return isCollectable;}

bool StaticEntity::GetIsCollider() const {return isCollider;}

