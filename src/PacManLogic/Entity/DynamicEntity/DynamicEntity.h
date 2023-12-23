//

#ifndef PACMAN_DYNAMICENTITY_H
#define PACMAN_DYNAMICENTITY_H

#include "Entity/Entity.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"
#include "Events/EntityEvent/EntityDirectionChangeEvent.h"

/**
 * @brief An entity that is dynamic (can change positions/move) and can also be killable by other dynamic entities
 */
class DynamicEntity : public PMLogic::Entity {
protected:
    /**
     * @brief Starting position.
     */
    const Coordinate2D::NormalizedCoordinate spawn;

    /**
     * @brief Current direction.
     */
    Coordinate2D::DiscreteDirection2D currentDirection;
    /**
     * @brief Direction that the dynamic entity wishes to change to
     */
    Coordinate2D::DiscreteDirection2D nextDirection;

    /**
     * @brief Directions that are currently viable to choose
     */
    std::list<Coordinate2D::DiscreteDirection2D> viableDirections;

    /**
     * @brief Default speed.
     */
    const float defaultSpeed;

    /**
     * @brief Current speed.
     */
    float speed;

    /**
     * @brief 'Invincibility' status.
     */
    bool isKillable;

public:
    std::unique_ptr<EntityPositionChangeEvent> onPositionChange;
    std::unique_ptr<EntityDirectionChangeEvent> onDirectionChange;



    explicit DynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                           const Coordinate2D::Coordinate &size,
                           const float &speed);
    ~DynamicEntity() override = default;

    /**
     * @brief Moves the entity
     */
    void Move();

    /**
     * @brief Set the position.
     * @param newPosition The new position.
     */
    void SetPosition(const Coordinate2D::Coordinate &newPosition);


    /**
     * @brief Gets the current speed.
     * @return The current speed.
     */
    float GetSpeed() const;
    /**
     * @brief Sets the current speed.
     * @param newSpeed The new current speed.
     */
    void SetSpeed(const float &newSpeed);

    /**
     * @brief Gets the default speed.
     * @return The default speed.
     */
    float GetDefaultSpeed() const;

    /**
     * @brief Sets the next direction (not necessarily the current direction yet)
     * @param newDirection The new next direction
     */
    void SetNextDirection(const Coordinate2D::DiscreteDirection2D &newDirection);
    /**
     * @brief Sets current direction
     * @param newDirection The new current direction.
     */
    void SetDirection(const Coordinate2D::DiscreteDirection2D &newDirection);
    /**
     * @brief Gets current direction
     * @return The current direction
     */
    Coordinate2D::DiscreteDirection2D GetDirection() const;

    /**
     * @brief Gets next position of the dynamic entity in the current direction.
     * @return The next position.
     */
    Coordinate2D::NormalizedCoordinate GetNextPosition() const;
    /**
     * @brief Gets next position of the dynamic entity in a given direction.
     * @param direction The given direction.
     * @return The next position.
     */
    Coordinate2D::NormalizedCoordinate GetNextPosition(const Coordinate2D::DiscreteDirection2D &direction) const;

    /**
     * @brief Tells if the dynamic entity is killable.
     * @return Boolean denoting if the dynamic entity is killable.
     */
    bool GetIsKillable() const;
    /**
     * @brief Sets the killable boolean of the dynamic entity.
     * @param newIsKillable The new killable boolean.
     */
    void SetIsKillable(const bool &newIsKillable);

    /**
     * @brief Tells if the dynamic entity will collide with another entity in the next position/move.
     * @param entity
     * @return Boolean denoting if the dynamic entity will collide with another entity.
     */
    bool WillCollide(const PMLogic::Entity &entity) const override;
    /**
     * @brief Tells if the dynamic entity will collide with another entity in the position in a given direction.
     * @param entity
     * @return Boolean denoting if the dynamic entity will collide with another entity given a direction.
     */
    bool WillCollide(const PMLogic::Entity &entity, const Coordinate2D::DiscreteDirection2D &direction) const;


    // dynamic double dispatch for collisions

    /**
     * @brief Handle collision with itself and wall
     */
    void CollideWith(Wall &) override;
    /**
     * @brief Handle collision with itself and intersection
     */
    void CollideWith(Intersection &) override;

    /**
     * @brief Handle collision with itself and ghost
     */
    void CollideWith(PacMan &) override {}

    /**
     * @brief Handle collision with itself and ghost
     */
    void CollideWith(Ghost &) override {}

    /**
     * @brief Handle collision with itself and fruit
     */
    void CollideWith(Fruit &) override {}
    /**
     * @brief Handle collision with itself and coin
     */
    void CollideWith(Coin &) override {}
    /**
     * @brief Handle collision with itself and an entity
     */
    void CollideWith(PMLogic::Entity &) override = 0;

    /**
     * @brief Retrieve the starting position.
     * @return The starting position.
     */
    Coordinate2D::NormalizedCoordinate GetSpawn() const;

    /**
     * @brief Respawns the entity by setting the current position to spawn (the starting position)
     */
    void Respawn() override;
};

#endif // PACMAN_DYNAMICENTITY_H
