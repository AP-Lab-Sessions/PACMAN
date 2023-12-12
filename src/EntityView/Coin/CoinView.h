//

#ifndef PACMAN_COINVIEW_H
#define PACMAN_COINVIEW_H

#include "PacManLogic/Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "EntityView/View.h"

class CoinView final : public View<Coin> {
public:
    CoinView(const Coin &entity, const std::weak_ptr<sf::RenderWindow> &window);

    void Load() final;
    void Update() final;
};

#endif // PACMAN_COINVIEW_H
