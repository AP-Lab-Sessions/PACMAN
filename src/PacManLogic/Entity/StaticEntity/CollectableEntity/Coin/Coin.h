//

#ifndef PACMAN_COIN_H
#define PACMAN_COIN_H

#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class Coin : public CollectableEntity {
public:
    explicit Coin(const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size);

    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    void CollideWith(PMLogic::Entity &) override;
    void CollideWith(PacMan &) final;
};

#endif // PACMAN_COIN_H
