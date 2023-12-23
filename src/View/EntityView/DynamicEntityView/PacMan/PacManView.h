//

#ifndef PAC_MAN_PACMANVIEW_H
#define PAC_MAN_PACMANVIEW_H

#include "View/EntityView/DynamicEntityView/DynamicEntityView.h"

namespace PMGame::View {
/**
 * @brief View of the PacMan entity.
 */
class PacManView final : public DynamicEntityView {
protected:
public:
    explicit PacManView(const std::weak_ptr<sf::RenderWindow>& window);

    using DynamicEntityView::Update;

    /**
     * @brief Listens to the creation of PacMan entity and plays a sound.
     * @param event
     */
    void Update(const PMGame::Logic::EntityCreateEvent& event) final;
};
} // namespace PMGame::View
#endif // PAC_MAN_PACMANVIEW_H
