//

#include "GhostView.h"

GhostView::GhostView(const Ghost &entity, const std::weak_ptr<sf::RenderWindow> &window) :
        View<Ghost>(entity, window) {
    Load();
}

void GhostView::Load() {}

void GhostView::Update() {}
