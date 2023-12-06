//

#ifndef PACMAN_FRUIT_H
#define PACMAN_FRUIT_H

#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class Fruit : public CollectableEntity {
public:
    Fruit();

    void Accept(const std::weak_ptr<PMLogic::IVisitor> &visitor) const override;
};

#endif // PACMAN_FRUIT_H
