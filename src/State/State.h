//

#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H

#include <memory>
#include <SFML/Graphics.hpp>

class StateManager;

class State {
protected:
    std::weak_ptr<StateManager> manager;
public:
    virtual ~State() = default;

    void SetManager(const std::weak_ptr<StateManager> &);

    virtual void Run(sf::RenderWindow &window) = 0;
};

#endif // PACMAN_STATE_H
