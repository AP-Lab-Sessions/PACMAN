//

#ifndef PACMAN_STATEMANAGER_H
#define PACMAN_STATEMANAGER_H

#include "State/State.h"
#include <SFML/Graphics.hpp>
#include <stack>

class StateManager : public std::enable_shared_from_this<StateManager> {
private:
    std::stack<std::unique_ptr<State>> stateStack;
public:
    explicit StateManager(std::unique_ptr<State> &state);

    void PushState(std::unique_ptr<State> &state);
    void PopState();
    void Run(sf::RenderWindow &window);
};

#endif // PACMAN_STATEMANAGER_H
