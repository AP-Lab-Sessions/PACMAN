//

#include "CoinView.h"

CoinView::CoinView(const Coin &entity, const std::weak_ptr<sf::RenderWindow> &window) :
        View<Coin>(entity, window) {
    Load();
}

void CoinView::Load() {
    const sf::Vector2f viewSize = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(
            static_cast<unsigned int>(viewSize.x),
            static_cast<unsigned int>(viewSize.y));
    const auto &size = camera.ProjectSize(entity);
    const auto &position = camera.ProjectCurrentPosition(entity);

    coin = sf::RectangleShape();
    coin.setFillColor(sf::Color::White);
    coin.setSize(sf::Vector2f{size.GetX(), size.GetY()});
    coin.setPosition(position.GetX(), position.GetY());
}

void CoinView::Render() {
    if(!entityDestroyed) {
        window.lock()->draw(coin);
    }
}