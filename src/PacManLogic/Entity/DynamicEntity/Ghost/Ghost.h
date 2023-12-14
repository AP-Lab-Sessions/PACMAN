//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Entity/DynamicEntity/DynamicEntity.h"

enum GhostMode {Mode_Normal, Mode_Fear};

class Ghost : public DynamicEntity {
protected:
    GhostMode mode;
public:
    explicit Ghost(const Coordinate2D::NormalizedCoordinate &startPosition);
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    void CollideWith(PacMan &) final;

    void CollideWith(PMLogic::Entity &) override;
};

#endif // PACMAN_GHOST_H
