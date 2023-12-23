//

#include "StateManager.h"
#include <iostream>

void StateManager::PushState(std::unique_ptr<State>& state) {
    state->SetManager(weak_from_this());
    stateStack.push(std::move(state));
}

void StateManager::PopState(const int& times) {
    for (int i = 0; i < times; i++) {
        if (!stateStack.empty()) {
            stateStack.pop();
        } else
            break;
    }
}

void StateManager::Render() { stateStack.top()->Render(); }

void StateManager::Update() { stateStack.top()->Update(); }

void StateManager::ProcessEvents(const sf::Event& event) { stateStack.top()->ProcessEvents(event); }