//

#ifndef PACMAN_FRUITVIEW_H
#define PACMAN_FRUITVIEW_H

#include "PacManLogic/Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "EntityView/View.h"

class FruitView final : public View<Fruit> {
public:
    FruitView(const Fruit &entity, const std::weak_ptr<sf::RenderWindow> &window);

    void Load() final;
};

#endif // PACMAN_FRUITVIEW_H
