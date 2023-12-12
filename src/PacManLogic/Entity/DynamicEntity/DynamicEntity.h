//

#ifndef PACMAN_DYNAMICENTITY_H
#define PACMAN_DYNAMICENTITY_H

#include "Entity/Entity.h"

enum DiscreteDirection2D {
    Direction_Left, Direction_Right, Direction_Up, Direction_Down
};

class DynamicEntity : public PMLogic::Entity {
protected:
    unsigned int lives;
    DiscreteDirection2D currentDirection;
    float speed;

public:
    explicit DynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                           const Coordinate2D::Coordinate &size,
                           const unsigned int &lives, const float &speed);
    ~DynamicEntity() override = default;

    void Move();

    float GetSpeed() const;
    void SetSpeed(const float &newSpeed);

    unsigned int GetLives() const;

    void SetDirection(const DiscreteDirection2D &newDirection);
    DiscreteDirection2D GetDirection() const;

    Coordinate2D::NormalizedCoordinate GetNextPosition() const;
};

#endif // PACMAN_DYNAMICENTITY_H
