//

#ifndef PACMAN_COINVIEW_H
#define PACMAN_COINVIEW_H

#include "PacManLogic/Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "EntityView/View.h"

template<>
class View<Coin> : public PMLogic::IObserver {
protected:
    const std::weak_ptr<Coin> entity;
public:
    void Update() override {}
};

#endif // PACMAN_COINVIEW_H
