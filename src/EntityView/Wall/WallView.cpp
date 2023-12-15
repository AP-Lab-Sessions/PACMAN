//

#include "WallView.h"

WallView::WallView(const Wall &entity, const std::weak_ptr<sf::RenderWindow> &window) : View<Wall>(entity, window) {
    Load();
}

void WallView::Render() {
    if(!entityDestroyed) {
        window.lock()->draw(wall);
    }
}

void WallView::Load() {
    const sf::Vector2f viewSize = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(
            static_cast<unsigned int>(viewSize.x),
            static_cast<unsigned int>(viewSize.y));
    const auto &size = camera.ProjectSize(entity);
    const auto &position = camera.ProjectCurrentPosition(entity);

    wall = sf::RectangleShape();
    wall.setFillColor(sf::Color::Blue);
    wall.setSize(sf::Vector2f{size.GetX(), size.GetY()});
    wall.setPosition(position.GetX(), position.GetY());
}