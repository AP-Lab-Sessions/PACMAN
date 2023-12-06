//

#include "State.h"

void State::SetManager(const std::weak_ptr<StateManager>& managerArg) {
    manager = managerArg;
}