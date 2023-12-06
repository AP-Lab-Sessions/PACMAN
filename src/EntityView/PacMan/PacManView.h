//

#ifndef PAC_MAN_PACMANVIEW_H
#define PAC_MAN_PACMANVIEW_H

#include "PacManLogic/Entity/DynamicEntity/PacMan/PacMan.h"
#include "EntityView/View.h"

template<>
class View<PacMan> : public PMLogic::IObserver {
protected:
    const std::weak_ptr<PacMan> entity;
public:
    void Update() override {}
};

#endif // PAC_MAN_PACMANVIEW_H
