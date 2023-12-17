//

#ifndef PACMAN_FRUITVIEW_H
#define PACMAN_FRUITVIEW_H

#include "EntityView/EntityView.h"

class FruitView final : public EntityView {
public:
    explicit FruitView(const std::weak_ptr<sf::RenderWindow> &window);
};

#endif // PACMAN_FRUITVIEW_H
