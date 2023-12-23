//

#include "CoinView.h"
#include "View/SoundManager/SoundManager.h"

PMGame::View::CoinView::CoinView(const std::weak_ptr<sf::RenderWindow>& window) : EntityView(window) {}

void PMGame::View::CoinView::Update(const PMGame::Logic::EntityCreateEvent& eventData) {
    const sf::Vector2f viewSize = window.lock()->getDefaultView().getSize();

    PMGame::Logic::Helper::Camera camera(static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y));
    const auto& size = camera.ProjectSize(eventData.size);
    const auto& position = camera.Project(eventData.position);

    coin = sf::RectangleShape();
    coin.setFillColor(sf::Color::White);
    coin.setSize(sf::Vector2f{size.GetX(), size.GetY()});
    coin.setPosition(position.GetX(), position.GetY());
}

void PMGame::View::CoinView::Render() const {
    if (!entityDestroyed) {
        window.lock()->draw(coin);
    }
}

void PMGame::View::CoinView::Update(const PMGame::Logic::EntityCollectedEvent&) {
    const auto& soundBuffer = SoundManager::GetInstance().lock();
    soundBuffer->Play("assets/audio/pacman_chomp.wav");
}