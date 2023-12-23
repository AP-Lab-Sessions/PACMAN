//

#include "Game.h"
#include "View/State/MenuState/MenuState.h"

// simplify entityfactory,
PMGame::Game::Game(const unsigned int& width, const unsigned int& height) {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "PacMan",
                                                sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    view = window->getDefaultView();
    view.setCenter(static_cast<float>(window->getSize().x) / 2, static_cast<float>(window->getSize().y) / 2);
    view.setSize(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y));
    window->setFramerateLimit(144);
    window->setView(view);

    std::unique_ptr<View::State> startState{std::make_unique<View::MenuState>(window)};
    std::shared_ptr<View::StateManager> manager{new View::StateManager()};
    manager->PushState(startState);
    stateManager = manager;

    outline = sf::RectangleShape();
    outline.setSize(sf::Vector2f{static_cast<float>(width), static_cast<float>(height)});
    outline.setOutlineColor(sf::Color::White);
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineThickness(1.0f);
}
void PMGame::Game::Update() { stateManager->Update(); }
void PMGame::Game::Render() {
    window->clear();
    window->draw(outline);
    stateManager->Render();
    window->display();
}
void PMGame::Game::ProcessEvents() {
    sf::Event event{};
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::Resized) {
            view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
            window->setView(view);
        }
        stateManager->ProcessEvents(event);
    }
}
void PMGame::Game::Run() {
    while (window->isOpen()) {
        ProcessEvents();
        Update();
        Render();
    }
}