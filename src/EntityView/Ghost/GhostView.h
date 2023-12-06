//

#ifndef PACMAN_GHOSTVIEW_H
#define PACMAN_GHOSTVIEW_H

#include "PacManLogic/Entity/DynamicEntity/Ghost/Ghost.h"
#include "EntityView/View.h"

template<>
class View<Ghost> : public PMLogic::IObserver {
protected:
    const std::weak_ptr<Ghost> entity;
public:
    void Update() override {}

};

#endif // PACMAN_GHOSTVIEW_H
