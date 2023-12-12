//

#include "StateManager.h"
#include <iostream>


void StateManager::PushState(std::unique_ptr<State>& state) {
    state->SetManager(weak_from_this());
    stateStack.push(std::move(state));
}

void StateManager::PopState() {
    if(!stateStack.empty()) {
        stateStack.pop();
    }
}

void StateManager::Render() {
    stateStack.top()->Render();
}

void StateManager::Update() {
    stateStack.top()->Update();
}

void StateManager::ProcessEvents(const sf::Event &event) {
    stateStack.top()->ProcessEvents(event);
}