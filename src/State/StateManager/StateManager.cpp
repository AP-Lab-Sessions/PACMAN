//

#include "StateManager.h"

StateManager::StateManager(std::unique_ptr<State> &state) {
    PushState(state);
}

void StateManager::PushState(std::unique_ptr<State>& state) {
    state->SetManager(weak_from_this());
    stateStack.push(std::move(state));
}

void StateManager::PopState() {
    if(!stateStack.empty()) {
        stateStack.pop();
    }
}

void StateManager::Run(sf::RenderWindow &window) {
    stateStack.top()->Run(window);
}