//

#ifndef PACMAN_FRUITVIEW_H
#define PACMAN_FRUITVIEW_H

#include "EntityView/EntityView.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"

class FruitView final : public EntityView, public PMLogic::IEventListener<EntityCollectedEvent> {
public:
    explicit FruitView(const std::weak_ptr<sf::RenderWindow> &window);

    using EntityView::Update;

    void Update(const EntityCollectedEvent &eventData) final;
};

#endif // PACMAN_FRUITVIEW_H
