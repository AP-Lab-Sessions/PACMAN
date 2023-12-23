//

#include "WallView.h"

PMGame::View::WallView::WallView(const std::weak_ptr<sf::RenderWindow>& window) : EntityView(window) {}

void PMGame::View::WallView::Render() const {
    if (!entityDestroyed) {
        window.lock()->draw(wall);
    }
}

void PMGame::View::WallView::Update(const PMGame::Logic::EntityCreateEvent& eventData) {
    const sf::Vector2f viewSize = window.lock()->getDefaultView().getSize();

    PMGame::Logic::Helper::Camera camera(static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y));
    const auto& size = camera.ProjectSize(eventData.size);
    const auto& position = camera.Project(eventData.position);

    wall = sf::RectangleShape();
    wall.setFillColor(sf::Color::Blue);
    wall.setSize(sf::Vector2f{size.GetX(), size.GetY()});
    wall.setPosition(position.GetX(), position.GetY());
}