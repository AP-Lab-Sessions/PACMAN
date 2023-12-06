//

#ifndef PACMAN_FRUITVIEW_H
#define PACMAN_FRUITVIEW_H

#include "PacManLogic/Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "EntityView/View.h"

template<>
class View<Fruit> : public PMLogic::IObserver {
protected:
    const std::weak_ptr<Fruit> entity;
public:
    void Update() override {}
};

#endif // PACMAN_FRUITVIEW_H
