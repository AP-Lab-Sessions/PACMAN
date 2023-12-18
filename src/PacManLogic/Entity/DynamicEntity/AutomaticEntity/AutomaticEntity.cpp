//

#include "AutomaticEntity.h"

AutomaticEntity::AutomaticEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                                 const Coordinate2D::Coordinate& size,
                                 const float& speed)
    : DynamicEntity(startPosition, size, speed) {

}

void AutomaticEntity::Update(const EntityDestroyEvent& eventData) {
    target.reset();
}