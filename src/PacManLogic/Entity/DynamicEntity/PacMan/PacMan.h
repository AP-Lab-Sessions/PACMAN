//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "Entity/DynamicEntity/DynamicEntity.h"
#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class PacMan : public DynamicEntity {
public:
    void Eat(const CollectableEntity &collectable);
    void Accept(const std::weak_ptr<PMLogic::IVisitor> &visitor) const override;
};

#endif // PACMAN_PACMAN_H
