//

#include "State.h"
#include "Game/Assets.h"

void State::SetManager(const std::weak_ptr<StateManager>& managerArg) {
    manager = managerArg;
}

State::State(sf::RenderWindow &window) : window(window), mainFont(Assets::GetInstance().lock()->GetMainFont()) {}