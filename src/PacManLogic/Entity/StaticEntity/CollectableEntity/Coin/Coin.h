//

#ifndef PACMAN_COIN_H
#define PACMAN_COIN_H

#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class Coin : public CollectableEntity {
public:
    Coin();

    void Accept(const std::weak_ptr<PMLogic::IVisitor> &visitor) const override;
};

#endif // PACMAN_COIN_H
