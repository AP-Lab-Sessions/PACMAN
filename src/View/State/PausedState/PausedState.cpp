//

#include "PausedState.h"

#include "View/StateManager/StateManager.h"

PMGame::View::PausedState::PausedState(const std::weak_ptr<sf::RenderWindow>& window)
    : State(window),
      description(TextWidget("You paused the game.", secondaryFont, sf::Color::Yellow, 30,
                             {sf::Vector2f(window.lock()->getDefaultView().getSize()).x / 2.0f,
                              sf::Vector2f(window.lock()->getDefaultView().getSize()).y / 2.0f - 200.0f})),
      resume(TextWidget("Resume", secondaryFont, sf::Color::Yellow, 30,
                        {sf::Vector2f(window.lock()->getDefaultView().getSize()).x / 2.0f,
                         sf::Vector2f(window.lock()->getDefaultView().getSize()).y / 2.0f - 50.0f})),
      goToMenu(TextWidget("Exit to menu", secondaryFont, sf::Color::Yellow, 30,
                          {sf::Vector2f(window.lock()->getDefaultView().getSize()).x / 2.0f,
                           sf::Vector2f(window.lock()->getDefaultView().getSize()).y / 2.0f + 50.f})) {}

void PMGame::View::PausedState::ProcessEvents(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Key::Escape: {
            manager.lock()->PopState();
            break;
        }
        default: {
            break;
        }
        }
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = window.lock()->mapPixelToCoords(sf::Mouse::getPosition(*window.lock()));
            if (goToMenu.IsClicked(mouse)) {
                manager.lock()->PopState(2);
            } else if (resume.IsClicked(mouse)) {
                manager.lock()->PopState();
            }
        }
    }
}
void PMGame::View::PausedState::Update() {}

void PMGame::View::PausedState::Render() {
    const auto& renderWindow = window.lock();
    renderWindow->draw(description.text);
    renderWindow->draw(goToMenu.text);
    renderWindow->draw(resume.text);
}