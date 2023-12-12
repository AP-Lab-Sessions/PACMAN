//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Entity/DynamicEntity/DynamicEntity.h"

class Ghost : public DynamicEntity{
public:
    explicit Ghost(const Coordinate2D::NormalizedCoordinate &startPosition);
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;
};

#endif // PACMAN_GHOST_H
