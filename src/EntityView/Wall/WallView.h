//

#ifndef PACMAN_WALLVIEW_H
#define PACMAN_WALLVIEW_H

#include "EntityView/View.h"
#include "PacManLogic/Entity/StaticEntity/Wall/Wall.h"

class WallView final : public View<Wall> {
protected:
    sf::RectangleShape wallShape;
public:
    WallView(const Wall &entity, const std::weak_ptr<sf::RenderWindow> &window);

    void Load() final;
    void Update() final;
    void Render() override;
};

#endif // PACMAN_WALLVIEW_H
