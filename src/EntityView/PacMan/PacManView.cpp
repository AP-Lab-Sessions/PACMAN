//

#include "PacManView.h"

void PacManView::Load() {
    const sf::Vector2f size = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(
            static_cast<unsigned int>(size.x),
            static_cast<unsigned int>(size.y));

    sprite = spriteSheet.GetSprite(17,1, camera.ProjectSize(entity));
}
PacManView::PacManView(const PacMan &entity, const std::weak_ptr<sf::RenderWindow> &window)
: View<PacMan>(entity, window) {
    Load();
}

