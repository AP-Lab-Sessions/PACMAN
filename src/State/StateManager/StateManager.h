//

#ifndef PACMAN_STATEMANAGER_H
#define PACMAN_STATEMANAGER_H

#include "State/State.h"
#include <SFML/Graphics.hpp>
#include <stack>

class StateManager : public std::enable_shared_from_this<StateManager> {
protected:
    std::stack<std::unique_ptr<State>> stateStack;
public:
    StateManager() = default;

    void PushState(std::unique_ptr<State> &state);
    void PopState();

    void Update();
    void ProcessEvents(const sf::Event &event);
    void Render();
};

#endif // PACMAN_STATEMANAGER_H
