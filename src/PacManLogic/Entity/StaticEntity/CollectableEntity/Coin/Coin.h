//

#ifndef PACMAN_COIN_H
#define PACMAN_COIN_H

#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class Coin : public CollectableEntity {
public:
    explicit Coin(const Coordinate2D::NormalizedCoordinate &startPosition);

    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;
};

#endif // PACMAN_COIN_H
