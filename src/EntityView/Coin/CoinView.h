//

#ifndef PACMAN_COINVIEW_H
#define PACMAN_COINVIEW_H

#include "EntityView/EntityView.h"

class CoinView final : public EntityView {
protected:
    sf::RectangleShape coin;
public:
    explicit CoinView(const std::weak_ptr<sf::RenderWindow> &window);

    void Update(const EntityCreateEvent &eventData) final;

    void Render() const override;
};

#endif // PACMAN_COINVIEW_H
