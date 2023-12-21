//

#ifndef PACMAN_DYNAMICENTITY_H
#define PACMAN_DYNAMICENTITY_H

#include "Entity/Entity.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"
#include "Events/EntityEvent/EntityDirectionChangeEvent.h"

class DynamicEntity : public PMLogic::Entity {
protected:

    const Coordinate2D::NormalizedCoordinate spawn;

    Coordinate2D::DiscreteDirection2D currentDirection;
    Coordinate2D::DiscreteDirection2D nextDirection;

    std::list<Coordinate2D::DiscreteDirection2D> viableDirections;

    float defaultSpeed, speed;

    bool isKillable;
public:
    std::unique_ptr<EntityPositionChangeEvent> onPositionChange;
    std::unique_ptr<EntityDirectionChangeEvent> onDirectionChange;



    explicit DynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                           const Coordinate2D::Coordinate &size,
                           const float &speed);
    ~DynamicEntity() override = default;

    void Move();

    void SetPosition(const Coordinate2D::NormalizedCoordinate &newPosition);


    float GetSpeed() const;
    void SetSpeed(const float &newSpeed);

    float GetDefaultSpeed() const;

    void SetNextDirection(const Coordinate2D::DiscreteDirection2D &newDirection);
    void SetDirection(const Coordinate2D::DiscreteDirection2D &newDirection);
    Coordinate2D::DiscreteDirection2D GetDirection() const;

    Coordinate2D::NormalizedCoordinate GetNextPosition() const;
    Coordinate2D::NormalizedCoordinate GetNextPosition(const Coordinate2D::DiscreteDirection2D &direction) const;

    bool GetIsKillable() const;
    void SetIsKillable(const bool &newIsKillable);

    bool WillCollide(const PMLogic::Entity &entity) const override;
    bool WillCollide(const PMLogic::Entity &entity, const Coordinate2D::DiscreteDirection2D &direction) const;

    void CollideWith(Wall &) override;
    void CollideWith(PacMan &) override {}
    void CollideWith(Ghost &) override {}
    void CollideWith(Fruit &) override {}
    void CollideWith(Coin &) override {}
    void CollideWith(PMLogic::Entity &) override = 0;

    Coordinate2D::NormalizedCoordinate GetSpawn() const;

    void Respawn() override;
};

#endif // PACMAN_DYNAMICENTITY_H
