//

#ifndef PACMAN_FRUITVIEW_H
#define PACMAN_FRUITVIEW_H

#include "Events/EntityEvent/EntityCollectedEvent.h"
#include "View/EntityView/EntityView.h"

namespace PMGame::View {
/**
 * @brief View of a fruit entity, the view additionally listens whenever the fruit gets collected
 */
class FruitView final : public EntityView, public PMGame::Logic::IEventListener<PMGame::Logic::EntityCollectedEvent> {
public:
    explicit FruitView(const std::weak_ptr<sf::RenderWindow>& window);

    using EntityView::Update;

    /**
     * @brief Gets called whenever the fruit gets collected and plays a sound
     * @param eventData
     */
    void Update(const PMGame::Logic::EntityCollectedEvent& eventData) final;
};
} // namespace PMGame::View

#endif // PACMAN_FRUITVIEW_H