//

#ifndef PACMAN_DYNAMICENTITY_H
#define PACMAN_DYNAMICENTITY_H

#include "Entity/Entity.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"
#include "Events/EntityEvent/EntityDirectionChangeEvent.h"

class DynamicEntity : public PMLogic::Entity {
protected:
    unsigned int lives;
    DiscreteDirection2D currentDirection;

    float defaultSpeed, speed;

    bool canMove;
    bool isKillable;
public:
    std::unique_ptr<EntityPositionChangeEvent> onPositionChange;
    std::unique_ptr<EntityDirectionChangeEvent> onDirectionChange;



    explicit DynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                           const Coordinate2D::Coordinate &size,
                           const unsigned int &lives, const float &speed);
    ~DynamicEntity() override = default;

    void Move();

    void SetPosition(const Coordinate2D::NormalizedCoordinate &newPosition);


    float GetSpeed() const;
    void SetSpeed(const float &newSpeed);

    float GetDefaultSpeed() const;

    unsigned int GetLives() const;

    void SetDirection(const DiscreteDirection2D &newDirection);
    DiscreteDirection2D GetDirection() const;

    Coordinate2D::NormalizedCoordinate GetNextPosition() const;
    Coordinate2D::NormalizedCoordinate GetNextPosition(const DiscreteDirection2D &direction) const;

    bool GetCanMove() const;
    void SetCanMove(const bool &newCanMove);

    bool GetIsKillable() const;
    void SetIsKillable(const bool &newIsKillable);

    bool WillCollide(const PMLogic::Entity &entity) const override;
    bool WillCollide(const PMLogic::Entity &entity, const DiscreteDirection2D &direction) const;

    void CollideWith(Wall &) override;
    void CollideWith(PacMan &) override {}
    void CollideWith(Ghost &) override {}
    void CollideWith(Fruit &) override {}
    void CollideWith(Coin &) override {}
    void CollideWith(PMLogic::Entity &) override = 0;
};

#endif // PACMAN_DYNAMICENTITY_H
