//

#ifndef PACMAN_DYNAMICENTITY_H
#define PACMAN_DYNAMICENTITY_H

#include "Entity/Entity.h"

enum DiscreteDirection2D {
    Direction_Left, Direction_Right, Direction_Up, Direction_Down
};

class DynamicEntity : public PMLogic::Entity {
protected:
    Coordinate2D::NormalizedCoordinate currentPosition;
    bool isAlive;
    DiscreteDirection2D currentDirection;
public:
    explicit DynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition);
    DynamicEntity();
    ~DynamicEntity() override = default;

    Coordinate2D::NormalizedCoordinate GetCurrentPosition() const override;
    void SetCurrentPosition(const Coordinate2D::NormalizedCoordinate &);
};

#endif // PACMAN_DYNAMICENTITY_H
