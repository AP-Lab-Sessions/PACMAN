//

#ifndef PACMAN_STATICENTITY_H
#define PACMAN_STATICENTITY_H

#include "Entity/Entity.h"

class StaticEntity : public PMLogic::Entity {
public:
    ~StaticEntity() override = default;
    StaticEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                 const Coordinate2D::Coordinate &size);

    bool WillCollide(const PMLogic::Entity &entity) const override;
};

#endif // PACMAN_STATICENTITY_H
