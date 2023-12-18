//

#ifndef PACMAN_FRUIT_H
#define PACMAN_FRUIT_H

#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class Fruit : public CollectableEntity {
public:
    explicit Fruit(const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size);

    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    void CollideWith(PMLogic::Entity &) override;
    void CollideWith(PacMan &) final;
};

#endif // PACMAN_FRUIT_H
