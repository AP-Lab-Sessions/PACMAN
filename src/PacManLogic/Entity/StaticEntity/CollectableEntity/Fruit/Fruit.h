//

#ifndef PACMAN_FRUIT_H
#define PACMAN_FRUIT_H

#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class Fruit : public CollectableEntity {
public:
    explicit Fruit(const Coordinate2D::NormalizedCoordinate &startPosition);

    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;
};

#endif // PACMAN_FRUIT_H
