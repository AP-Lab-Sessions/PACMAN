//

#ifndef PACMAN_GHOSTVIEW_H
#define PACMAN_GHOSTVIEW_H

#include "EntityView/DynamicEntityView/DynamicEntityView.h"
#include "Events/EntityEvent/GhostEvent/GhostModeChangeEvent.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"

/**
 * @brief View of the ghost entity, listens to ghost mode change and when the ghost is eaten by pacman.
 */
class GhostView final : public DynamicEntityView,
                        public PMLogic::IEventListener<GhostModeChangeEvent>,
                        public PMLogic::IEventListener<EntityCollectedEvent>{
public:
    explicit GhostView(const std::weak_ptr<sf::RenderWindow> &window);

    using DynamicEntityView::Update;

    /**
     * @brief Changes the sprite accordingly whenever the mode of the ghost changes.
     * @param eventData information about which mode the ghost changed to
     */
    void Update(const GhostModeChangeEvent &eventData) final;
    /**
     * @brief Plays a sound when the ghost has been eaten by pacman.
     * @param eventData
     */
    void Update(const EntityCollectedEvent &eventData) final;
};

#endif // PACMAN_GHOSTVIEW_H
