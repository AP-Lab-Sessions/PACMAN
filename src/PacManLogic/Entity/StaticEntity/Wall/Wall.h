//

#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H

#include "Entity/StaticEntity/StaticEntity.h"

class Wall : public StaticEntity {
public:
    Wall(const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size);

    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    void CollideWith(PMLogic::Entity &) override;
};

#endif // PACMAN_WALL_H
