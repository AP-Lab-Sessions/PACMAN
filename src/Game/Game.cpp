//

#include "Game.h"
#include "State/MenuState/MenuState.h"

// TODO: valgrind "conditional jump/moves depends on uninitialised value(s), simplify entityfactory
Game::Game(const unsigned int &width, const unsigned int &height) : width(width), height(height)
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width,height), "PacMan",
                                                sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    view = window->getDefaultView();
    view.setCenter(static_cast<float>(window->getSize().x)/2, static_cast<float>(window->getSize().y)/2);
    view.setSize(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y));
    window->setFramerateLimit(144);
    window->setView(view);

    std::unique_ptr<State> startState {std::make_unique<MenuState>(window)};
    std::shared_ptr<StateManager> manager {new StateManager()};
    manager->PushState(startState);
    stateManager = manager;

    background = sf::RectangleShape();
    background.setSize(sf::Vector2f{static_cast<float>(width), static_cast<float>(height)});
    background.setOutlineColor(sf::Color::White);
    background.setFillColor(sf::Color::Transparent);
    background.setOutlineThickness(1.0f);
}
void Game::Update() {
    stateManager->Update();
}
void Game::Render() {
    window->clear();
    window->draw(background);
    stateManager->Render();
    window->display();
}
void Game::ProcessEvents() {
    sf::Event event{};
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::Resized)
        {
            view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
            window->setView(view);
        }
        stateManager->ProcessEvents(event);
    }
}
void Game::Run() {
    while (window->isOpen())
    {
        ProcessEvents();
        Update();
        Render();
    }
}