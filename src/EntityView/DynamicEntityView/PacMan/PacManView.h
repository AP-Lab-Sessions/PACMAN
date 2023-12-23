//

#ifndef PAC_MAN_PACMANVIEW_H
#define PAC_MAN_PACMANVIEW_H

#include "EntityView/DynamicEntityView/DynamicEntityView.h"

/**
 * @brief View of the PacMan entity.
 */
class PacManView final : public DynamicEntityView {
protected:
public:
    explicit PacManView(const std::weak_ptr<sf::RenderWindow> &window);

    using DynamicEntityView::Update;

    /**
     * @brief Listens to the creation of PacMan entity and plays a sound.
     * @param event
     */
    void Update(const EntityCreateEvent &event) final;
};

#endif // PAC_MAN_PACMANVIEW_H
