//

#ifndef PACMAN_COINVIEW_H
#define PACMAN_COINVIEW_H

#include "EntityView/EntityView.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"

class CoinView final : public EntityView, public PMLogic::IEventListener<EntityCollectedEvent>
{
protected:
    sf::RectangleShape coin;
public:
    explicit CoinView(const std::weak_ptr<sf::RenderWindow> &window);

    using EntityView::Update;

    void Update(const EntityCreateEvent &eventData) final;

    void Update(const EntityCollectedEvent &eventData) final;

    void Render() const override;
};

#endif // PACMAN_COINVIEW_H
