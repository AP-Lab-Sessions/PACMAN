//

#ifndef PACMAN_WALLVIEW_H
#define PACMAN_WALLVIEW_H

#include "EntityView/EntityView.h"

/**
 * @brief View of the wall entity
 */
class WallView final : public EntityView {
protected:
    sf::RectangleShape wall;

public:
    explicit WallView(const std::weak_ptr<sf::RenderWindow>& window);

    void Render() const override;
    void Update(const EntityCreateEvent& eventData) final;
};

#endif // PACMAN_WALLVIEW_H
