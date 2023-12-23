//

#ifndef PACMAN_ENTITY_H
#define PACMAN_ENTITY_H

#include "Coordinate/Coordinate.h"

#include "Events/EntityEvent/EntityCreateEvent.h"
#include "Events/EntityEvent/EntityDestroyEvent.h"

#include <memory>

// forward declarations
class IEntityVisitor;
class PacMan;
class Ghost;
class Fruit;
class Coin;
class Wall;
class Intersection;

/**
 * @brief Abstract entity base class.
 */
class PMLogic::Entity {
protected:
    /**
     * @brief Current position.
     */
    Coordinate2D::NormalizedCoordinate position;
    /**
     * @brief Size.
     */
    const Coordinate2D::Coordinate size;

public:
    std::unique_ptr<EntityDestroyEvent> onEntityDestroy;
    std::unique_ptr<EntityCreateEvent> onEntityCreate;

    /**
     * @param startPosition The starting position of the entity.
     * @param size The size of the entity.
     */
    explicit Entity(Coordinate2D::NormalizedCoordinate startPosition, const Coordinate2D::Coordinate& size);
    virtual ~Entity();

    /**
     * @brief Get size of the entity.
     * @return The size of the entity.
     */
    Coordinate2D::Coordinate GetSize() const;

    /**
     * @brief Get position of the entity.
     * @return The position of the entity.
     */
    Coordinate2D::NormalizedCoordinate GetPosition() const;

    /**
     * @brief Calls the visit function of the visitor
     * @param visitor
     */
    virtual void Accept(const std::weak_ptr<IEntityVisitor>& visitor) = 0;

    /**
     * @brief Tells if the entity will collide with another
     * @param entity
     * @return Boolean denoting if the entity will collide with another.
     */
    virtual bool WillCollide(const PMLogic::Entity& entity) const = 0;

    /**
     * @brief Handle collision with itself and pacman
     */
    virtual void CollideWith(PacMan&);
    /**
     * @brief Handle collision with itself and ghost
     */
    virtual void CollideWith(Ghost&);
    /**
     * @brief Handle collision with itself and fruit
     */
    virtual void CollideWith(Fruit&);
    /**
     * @brief Handle collision with itself and coin
     */
    virtual void CollideWith(Coin&);
    /**
     * @brief Handle collision with itself and wall
     */
    virtual void CollideWith(Wall&);
    /**
     * @brief Handle collision with itself and intersection
     */
    virtual void CollideWith(Intersection&);
    /**
     * @brief Handle collision with itself and an entity
     */
    virtual void CollideWith(PMLogic::Entity&) = 0;

    /**
     * @brief Respawns the entity
     */
    virtual void Respawn();

    /**
     * @brief Will call the onEntityCreate event so all listeners of that event will know that the entity has been
     * created and is ready.
     */
    void Create() const;
};

#endif // PACMAN_ENTITY_H
