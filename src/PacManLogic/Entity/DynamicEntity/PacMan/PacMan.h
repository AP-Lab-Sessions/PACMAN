//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "Entity/DynamicEntity/DynamicEntity.h"
#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class PacMan : public DynamicEntity {
public:
    explicit PacMan(const Coordinate2D::NormalizedCoordinate &startPosition);

    void Eat(const CollectableEntity &collectable);
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;
};

#endif // PACMAN_PACMAN_H
