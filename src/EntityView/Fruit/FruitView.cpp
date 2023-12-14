//

#include "FruitView.h"

FruitView::FruitView(const Fruit &entity, const std::weak_ptr<sf::RenderWindow> &window) :
        View<Fruit>(entity, window) {
    Load();
}

void FruitView::Load() {
    const sf::Vector2f size = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(
            static_cast<unsigned int>(size.x),
            static_cast<unsigned int>(size.y));

    sprite = spriteSheet.GetSprite(12,0, camera.ProjectSize(entity));
    const auto &coords {camera.ProjectCurrentPosition(entity)};

    sprite.setPosition(coords.GetX(), coords.GetY());
}