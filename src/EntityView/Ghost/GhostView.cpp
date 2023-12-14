//

#include "GhostView.h"

GhostView::GhostView(const Ghost &entity, const std::weak_ptr<sf::RenderWindow> &window) :
        View<Ghost>(entity, window) {
    Load();
}

void GhostView::Load() {
    const sf::Vector2f size = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(
            static_cast<unsigned int>(size.x),
            static_cast<unsigned int>(size.y));

    sprite = spriteSheet.GetSprite(0,0, camera.ProjectSize(entity));
}