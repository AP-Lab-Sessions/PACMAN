//

#ifndef PACMAN_WALLVIEW_H
#define PACMAN_WALLVIEW_H

#include "PacManLogic/Entity/StaticEntity/Wall/Wall.h"
#include "EntityView/View.h"

template<>
class View<Wall> : public PMLogic::IObserver {
protected:
    const std::weak_ptr<Wall> entity;
public:
    void Update() override {}
};

#endif // PACMAN_WALLVIEW_H
