//

#include "StateManager.h"
#include <iostream>

void PMGame::View::StateManager::PushState(std::unique_ptr<State>& state) {
    state->SetManager(weak_from_this());
    stateStack.push(std::move(state));
}

void PMGame::View::StateManager::PopState(const int& times) {
    for (int i = 0; i < times; i++) {
        if (!stateStack.empty()) {
            stateStack.pop();
        } else
            break;
    }
}

void PMGame::View::StateManager::Render() { stateStack.top()->Render(); }

void PMGame::View::StateManager::Update() { stateStack.top()->Update(); }

void PMGame::View::StateManager::ProcessEvents(const sf::Event& event) { stateStack.top()->ProcessEvents(event); }