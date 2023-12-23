//

#include "AutomaticEntity.h"

PMGame::Logic::AutomaticEntity::AutomaticEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                                                const Coordinate2D::Coordinate& size, const float& speed)
    : DynamicEntity(startPosition, size, speed) {}

void PMGame::Logic::AutomaticEntity::Update(const EntityDestroyEvent&) { target.reset(); }