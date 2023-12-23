//

#include "CoinView.h"
#include "Game/SoundManager/SoundManager.h"

CoinView::CoinView(const std::weak_ptr<sf::RenderWindow>& window) : EntityView(window) {}

void CoinView::Update(const EntityCreateEvent& eventData) {
    const sf::Vector2f viewSize = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y));
    const auto& size = camera.ProjectSize(eventData.size);
    const auto& position = camera.Project(eventData.position);

    coin = sf::RectangleShape();
    coin.setFillColor(sf::Color::White);
    coin.setSize(sf::Vector2f{size.GetX(), size.GetY()});
    coin.setPosition(position.GetX(), position.GetY());
}

void CoinView::Render() const {
    if (!entityDestroyed) {
        window.lock()->draw(coin);
    }
}

void CoinView::Update(const EntityCollectedEvent&) {
    const auto& soundBuffer = SoundManager::GetInstance().lock();
    soundBuffer->Play("assets/audio/pacman_chomp.wav");
}