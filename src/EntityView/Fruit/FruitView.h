//

#ifndef PACMAN_FRUITVIEW_H
#define PACMAN_FRUITVIEW_H

#include "EntityView/EntityView.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"

/**
 * @brief View of a fruit entity, the view additionally listens whenever the fruit gets collected
 */
class FruitView final : public EntityView, public PMLogic::IEventListener<EntityCollectedEvent> {
public:
    explicit FruitView(const std::weak_ptr<sf::RenderWindow>& window);

    using EntityView::Update;

    /**
     * @brief Gets called whenever the fruit gets collected and plays a sound
     * @param eventData
     */
    void Update(const EntityCollectedEvent& eventData) final;
};

#endif // PACMAN_FRUITVIEW_H
