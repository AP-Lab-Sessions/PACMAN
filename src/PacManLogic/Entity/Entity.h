//

#ifndef PACMAN_ENTITY_H
#define PACMAN_ENTITY_H

#include "Coordinate/Coordinate.h"
#include "IEntityVisitor/IEntityVisitor.h"

#include "Events/EntityEvent/EntityDestroyEvent.h"
#include "Events/EntityEvent/EntityCreateEvent.h"

#include <memory>

class PMLogic::Entity {
protected:
    Coordinate2D::NormalizedCoordinate position;
    const Coordinate2D::Coordinate size;

public:
    std::unique_ptr<EntityDestroyEvent> onEntityDestroy;
    std::unique_ptr<EntityCreateEvent> onEntityCreate;


    Coordinate2D::Coordinate GetSize() const;

    explicit Entity(Coordinate2D::NormalizedCoordinate startPosition, const Coordinate2D::Coordinate &size);
    virtual ~Entity() = default;

    Coordinate2D::NormalizedCoordinate GetPosition() const;

    virtual void Accept(const std::weak_ptr<IEntityVisitor> &visitor) = 0;

    virtual bool WillCollide(const PMLogic::Entity &entity) const = 0;

    // dynamic double dispatch for collision

    virtual void CollideWith(PacMan &) {}
    virtual void CollideWith(Ghost &) {}
    virtual void CollideWith(Fruit &) {}
    virtual void CollideWith(Coin &) {}
    virtual void CollideWith(Wall &) {}
    virtual void CollideWith(PMLogic::Entity &) = 0;

    virtual void Respawn() {}

    void Create() const;
};

#endif // PACMAN_ENTITY_H
