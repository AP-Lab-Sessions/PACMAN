//

#include "GameOverState.h"
#include "State/StateManager/StateManager.h"

GameOverState::GameOverState(const std::weak_ptr<sf::RenderWindow>& window)
    : State(window),
      description(TextWidget("Game over.", secondaryFont, sf::Color::Yellow, 30,
                             {sf::Vector2f(window.lock()->getDefaultView().getSize()).x / 2.0f,
                              sf::Vector2f(window.lock()->getDefaultView().getSize()).y / 2.0f - 200.0f})),
      goToMenu(TextWidget("Exit to menu", secondaryFont, sf::Color::Yellow, 30,
                          {sf::Vector2f(window.lock()->getDefaultView().getSize()).x / 2.0f,
                           sf::Vector2f(window.lock()->getDefaultView().getSize()).y / 2.0f - 50.0f})) {}

void GameOverState::ProcessEvents(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = window.lock()->mapPixelToCoords(sf::Mouse::getPosition(*window.lock()));
            if (goToMenu.IsClicked(mouse)) {
                manager.lock()->PopState(2);
            }
        }
    }
}

void GameOverState::Update() {}

void GameOverState::Render() {
    const auto& renderWindow = window.lock();
    renderWindow->draw(description.text);
    renderWindow->draw(goToMenu.text);
}