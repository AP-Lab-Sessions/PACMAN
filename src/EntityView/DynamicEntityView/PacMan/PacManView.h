//

#ifndef PAC_MAN_PACMANVIEW_H
#define PAC_MAN_PACMANVIEW_H

#include "EntityView/DynamicEntityView/DynamicEntityView.h"

class PacManView final : public DynamicEntityView {
protected:
public:
    explicit PacManView(const std::weak_ptr<sf::RenderWindow> &window);
};

#endif // PAC_MAN_PACMANVIEW_H
