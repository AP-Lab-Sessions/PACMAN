//

#include "WallView.h"

WallView::WallView(const std::weak_ptr<sf::RenderWindow>& window) : EntityView(window) {}

void WallView::Render() const {
    if (!entityDestroyed) {
        window.lock()->draw(wall);
    }
}

void WallView::Update(const EntityCreateEvent& eventData) {
    const sf::Vector2f viewSize = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y));
    const auto& size = camera.ProjectSize(eventData.size);
    const auto& position = camera.Project(eventData.position);

    wall = sf::RectangleShape();
    wall.setFillColor(sf::Color::Blue);
    wall.setSize(sf::Vector2f{size.GetX(), size.GetY()});
    wall.setPosition(position.GetX(), position.GetY());
}