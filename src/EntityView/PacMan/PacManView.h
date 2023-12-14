//

#ifndef PAC_MAN_PACMANVIEW_H
#define PAC_MAN_PACMANVIEW_H

#include "PacManLogic/Entity/DynamicEntity/PacMan/PacMan.h"
#include "EntityView/View.h"

class PacManView final : public View<PacMan> {
protected:
public:
    PacManView(const PacMan &entity, const std::weak_ptr<sf::RenderWindow> &window);

    void Load() final;
};

#endif // PAC_MAN_PACMANVIEW_H
