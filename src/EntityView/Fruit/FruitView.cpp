//

#include "FruitView.h"

FruitView::FruitView(const Fruit &entity, const std::weak_ptr<sf::RenderWindow> &window) :
        View<Fruit>(entity, window) {
    Load();
}

void FruitView::Update() {}

void FruitView::Load() {}