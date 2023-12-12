//

#include "PacManView.h"

void PacManView::Load() {
    const sf::Vector2f size = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(
            static_cast<unsigned int>(size.x),
            static_cast<unsigned int>(size.y));

    sprite = spriteSheet.GetSprite(17,1, camera.ProjectSize(entity));

    /*outline = sf::RectangleShape();
    outline.setOutlineThickness(1.0f);
    outline.setOutlineColor(sf::Color::White);
    outline.setFillColor(sf::Color::Transparent);
    outline.setSize(sf::Vector2f{(float)sprite.getTextureRect().width, (float)sprite.getTextureRect().height});
    outline.setScale(sprite.getScale());*/
}
PacManView::PacManView(const PacMan &entity, const std::weak_ptr<sf::RenderWindow> &window)
: View<PacMan>(entity, window) {
    Load();
}
void PacManView::Update() {
    const sf::Vector2f size = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(
            static_cast<unsigned int>(size.x),
            static_cast<unsigned int>(size.y));
    const auto &coords {camera.ProjectCurrentPosition(entity)};

    sprite.setPosition(coords.GetX(), coords.GetY());
    //outline.setPosition(coords.GetX(), coords.GetY());
}

