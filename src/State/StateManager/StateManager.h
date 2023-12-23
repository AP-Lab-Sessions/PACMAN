//

#ifndef PACMAN_STATEMANAGER_H
#define PACMAN_STATEMANAGER_H

#include "State/State.h"
#include <SFML/Graphics.hpp>
#include <stack>

/**
 * @brief Manages the states for GUI management
 */
class StateManager : public std::enable_shared_from_this<StateManager> {
protected:
    /**
     * @brief Stack of states.
     */
    std::stack<std::unique_ptr<State>> stateStack;

public:
    StateManager() = default;

    /**
     * @brief Pushes a new state to stateStack
     * @param state The new state
     */
    void PushState(std::unique_ptr<State>& state);
    /**
     * @brief Pops the stack n times and therefore the state(s) at the top
     * @param times
     */
    void PopState(const int& times = 1);

    /**
     * @brief Updates the state at the top of the stack.
     */
    void Update();
    /**
     * @brief Processes the events of the state at the top of the stack.
     * @param event
     */
    void ProcessEvents(const sf::Event& event);
    /**
     * @brief Renders the state at the top of the stack.
     */
    void Render();
};

#endif // PACMAN_STATEMANAGER_H
