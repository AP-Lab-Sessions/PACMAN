//

#include "AutomaticEntity.h"

AutomaticEntity::AutomaticEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                                 const Coordinate2D::Coordinate& size,
                                 const unsigned int& lives, const float& speed)
    : DynamicEntity(startPosition, size, lives, speed) {

}