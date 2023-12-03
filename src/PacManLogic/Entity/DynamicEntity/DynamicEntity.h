//

#ifndef PACMAN_DYNAMICENTITY_H
#define PACMAN_DYNAMICENTITY_H

#include "Entity/Entity.h"

class DynamicEntity : public PMLogic::Entity {
protected:
    Coordinate2D::NormalizedCoordinate currentPosition;
public:
    explicit DynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition);
    DynamicEntity();
};

#endif // PACMAN_DYNAMICENTITY_H
