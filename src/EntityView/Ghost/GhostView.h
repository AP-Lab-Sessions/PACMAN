//

#ifndef PACMAN_GHOSTVIEW_H
#define PACMAN_GHOSTVIEW_H

#include "EntityView/DynamicEntityView.h"
#include "Events/GhostEvent/GhostModeChangeEvent.h"

class GhostView final : public DynamicEntityView,
                        public PMLogic::IEventListener<GhostModeChangeEvent>{
public:
    explicit GhostView(const std::weak_ptr<sf::RenderWindow> &window);

    using DynamicEntityView::Update;
    void Update(const GhostModeChangeEvent &eventData) final;
};

#endif // PACMAN_GHOSTVIEW_H
