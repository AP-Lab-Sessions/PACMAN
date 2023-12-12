//

#include "Game.h"
#include "State/MenuState/MenuState.h"
#include "PacManLogic/Helper/StopWatch/StopWatch.h"

Game::Game(const unsigned int &width, const unsigned int &height) : view(sf::View()), width(width), height(height)
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width,height), "PacMan",
                                                sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

    view.setCenter(static_cast<float>(window->getSize().x)/2, static_cast<float>(window->getSize().y)/2);
    view.setSize(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y));
    window->setFramerateLimit(144);
    window->setView(view);

    std::unique_ptr<State> startState {std::make_unique<MenuState>(window)};
    std::shared_ptr<StateManager> manager {new StateManager()};
    manager->PushState(startState);
    stateManager = manager;

    background = sf::RectangleShape();
    background.setSize(sf::Vector2f{(float)width, (float)height});
    background.setOutlineColor(sf::Color::White);
    background.setFillColor(sf::Color::Transparent);
    background.setOutlineThickness(1.0f);
}
void Game::Update() {
    std::weak_ptr<PMLogic::Helper::StopWatch> stopWatch = PMLogic::Helper::StopWatch::GetInstance();
    stopWatch.lock()->Tick();
    stateManager->Update();
}
void Game::Render() {
    window->clear();
    window->draw(background);
    stateManager->Render();
    window->display();
}
#include <iostream>
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