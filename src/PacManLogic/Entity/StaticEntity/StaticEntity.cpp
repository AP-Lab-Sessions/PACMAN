//

#include "StaticEntity.h"

StaticEntity::StaticEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                           const Coordinate2D::Coordinate &size)
    : PMLogic::Entity(startPosition, size) {}

bool StaticEntity::WillCollide(const PMLogic::Entity &entity) const {
    return Coordinate2D::IsOverlapping(GetPosition(), GetSize(), entity.GetPosition(), entity.GetSize());
}

