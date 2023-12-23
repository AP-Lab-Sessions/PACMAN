//

#include "StaticEntity.h"

PMGame::Logic::StaticEntity::StaticEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                                          const Coordinate2D::Coordinate& size)
    : PMGame::Logic::Entity(startPosition, size) {}

bool PMGame::Logic::StaticEntity::WillCollide(const PMGame::Logic::Entity& entity) const {
    return Coordinate2D::IsOverlapping(GetPosition(), GetSize(), entity.GetPosition(), entity.GetSize());
}
