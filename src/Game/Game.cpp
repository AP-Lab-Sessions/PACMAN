//

#include "Game.h"
#include "State/MenuState/MenuState.h"
#include "PacManLogic/Helper/StopWatch/StopWatch.h"

Game::Game() : views(new std::vector<std::shared_ptr<PMLogic::IObserver>>()),
               window(new sf::RenderWindow(sf::VideoMode(800,600), "PacMan", sf::Style::Resize))
{
    window->setFramerateLimit(144);
    std::unique_ptr<State> startState {std::make_unique<MenuState>(*window)};
    std::shared_ptr<StateManager> manager {new StateManager()};
    manager->PushState(startState);
    stateManager = manager;
}
void Game::Update() {
    std::weak_ptr<PMLogic::Helper::StopWatch> stopWatch = PMLogic::Helper::StopWatch::GetInstance();
    stopWatch.lock()->Tick();
    stateManager->Update();
}
void Game::Render() {
    window->clear();
    stateManager->Render();
    window->display();
}
void Game::Run() {
    while (window->isOpen())
    {
        stateManager->ProcessEvents();
        Update();
        Render();
    }
}