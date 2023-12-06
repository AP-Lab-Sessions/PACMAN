//

#ifndef PACMAN_STATICENTITY_H
#define PACMAN_STATICENTITY_H

#include "Entity/Entity.h"

class StaticEntity : public PMLogic::Entity {
protected:
    bool isCollectable; // can be collected
    bool isCollider; // Causes collisions between dynamic entities
public:
    ~StaticEntity() override = default;
    StaticEntity(const bool &isCollectable, const bool &isCollider);

    bool GetIsCollectable() const;
    bool GetIsCollider() const;

};

#endif // PACMAN_STATICENTITY_H
