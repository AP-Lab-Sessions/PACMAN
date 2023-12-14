//

#include "CoinView.h"

CoinView::CoinView(const Coin &entity, const std::weak_ptr<sf::RenderWindow> &window) :
        View<Coin>(entity, window) {
    Load();
}

void CoinView::Load() {}

