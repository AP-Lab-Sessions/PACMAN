//

#ifndef PACMAN_GHOSTVIEW_H
#define PACMAN_GHOSTVIEW_H

#include "PacManLogic/Entity/DynamicEntity/Ghost/Ghost.h"
#include "EntityView/View.h"


class GhostView final : public View<Ghost> {
public:
    GhostView(const Ghost &entity, const std::weak_ptr<sf::RenderWindow> &window);

    void Load() final;
};

#endif // PACMAN_GHOSTVIEW_H
