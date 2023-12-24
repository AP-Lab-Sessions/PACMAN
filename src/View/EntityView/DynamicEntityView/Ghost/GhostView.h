//

#ifndef PACMAN_GHOSTVIEW_H
#define PACMAN_GHOSTVIEW_H

#include "Events/EntityEvent/EntityCollectedEvent.h"
#include "Events/EntityEvent/GhostEvent/GhostModeChangeEvent.h"
#include "View/EntityView/DynamicEntityView/DynamicEntityView.h"

namespace PMGame::View {
/**
 * @brief View of the ghost entity, listens to ghost mode change and when the ghost is eaten by pacman.
 */
class GhostView final : public DynamicEntityView,
                        public PMGame::Logic::IEventListener<PMGame::Logic::GhostModeChangeEvent>,
                        public PMGame::Logic::IEventListener<PMGame::Logic::EntityCollectedEvent> {
public:
    explicit GhostView(const std::weak_ptr<sf::RenderWindow>& window);

    using DynamicEntityView::Update;

    /**
     * @brief Changes the sprite accordingly whenever the mode of the ghost changes.
     * @param eventData information about which mode the ghost changed to
     */
    void Update(const PMGame::Logic::GhostModeChangeEvent& eventData) final;
    /**
     * @brief Plays a sound when the ghost has been eaten by pacman.
     * @param eventData
     */
    void Update(const PMGame::Logic::EntityCollectedEvent& eventData) final;
};
} // namespace PMGame::View
#endif // PACMAN_GHOSTVIEW_H