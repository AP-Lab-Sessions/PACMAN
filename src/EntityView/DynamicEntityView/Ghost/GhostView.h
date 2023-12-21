//

#ifndef PACMAN_GHOSTVIEW_H
#define PACMAN_GHOSTVIEW_H

#include "EntityView/DynamicEntityView/DynamicEntityView.h"
#include "Events/EntityEvent/GhostEvent/GhostModeChangeEvent.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"

class GhostView final : public DynamicEntityView,
                        public PMLogic::IEventListener<GhostModeChangeEvent>,
                        public PMLogic::IEventListener<EntityCollectedEvent>{
public:
    explicit GhostView(const std::weak_ptr<sf::RenderWindow> &window);

    using DynamicEntityView::Update;
    void Update(const GhostModeChangeEvent &eventData) final;
    void Update(const EntityCollectedEvent &eventData) final;
};

#endif // PACMAN_GHOSTVIEW_H
