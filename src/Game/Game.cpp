//

#include "Game.h"
#include "State/MenuState/MenuState.h"
#include "PacManLogic/Helper/StopWatch/StopWatch.h"
#include <iostream>

Game::Game() : views(new std::vector<std::shared_ptr<PMLogic::IObserver>>()),
               window(new sf::RenderWindow(sf::VideoMode(800,600), "PacMan"))
{
    std::unique_ptr<State> startState {new MenuState()};
    stateManager = std::make_shared<StateManager>(startState);

    window->setFramerateLimit(144);
}
void Game::ProcessEvents() {
    sf::Event event{};
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window->close();
    }
}
void Game::Update() {
    std::weak_ptr<PMLogic::Helper::StopWatch> stopWatch = PMLogic::Helper::StopWatch::GetInstance();
    stopWatch.lock()->Tick();
}
void Game::Render() {
    window->clear();
    window->display();
}
void Game::Run() {
    // TODO
    while (window->isOpen())
    {
        ProcessEvents();
        Update();
        Render();
    }
}