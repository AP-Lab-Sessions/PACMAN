//

#include "PausedState.h"

#include "State/StateManager/StateManager.h"

PausedState::PausedState(const std::weak_ptr<sf::RenderWindow>& window)
    : State(window),
      description(ButtonWidget("You paused the game.", secondaryFont, sf::Color::Yellow, 30,
                               {sf::Vector2f(window.lock()->getDefaultView().getSize()).x/2.0f,
                                sf::Vector2f(window.lock()->getDefaultView().getSize()).y/2.0f-200.0f})),
      resume(ButtonWidget("Resume", secondaryFont, sf::Color::Yellow, 30,
                            {sf::Vector2f(window.lock()->getDefaultView().getSize()).x/2.0f,
                             sf::Vector2f(window.lock()->getDefaultView().getSize()).y/2.0f-50.0f})),
      goToMenu(ButtonWidget("Exit to menu", secondaryFont, sf::Color::Yellow, 30,
                          {sf::Vector2f(window.lock()->getDefaultView().getSize()).x/2.0f,
                           sf::Vector2f(window.lock()->getDefaultView().getSize()).y/2.0f+50.f}))
{}

void PausedState::ProcessEvents(const sf::Event& event) {
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
    }
    else if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse = window.lock()->mapPixelToCoords(sf::Mouse::getPosition(*window.lock()));
                if(goToMenu.IsClicked(mouse)) {
                    manager.lock()->PopState(2);
                }
                else if(resume.IsClicked(mouse)) {
                    manager.lock()->PopState();
                }
        }
    }
}
void PausedState::Update() {

}

void PausedState::Render() {
    const auto &renderWindow = window.lock();
    renderWindow->draw(description.text);
    renderWindow->draw(goToMenu.text);
    renderWindow->draw(resume.text);
}