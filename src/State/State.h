//

#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H

#include <memory>
#include <SFML/Graphics.hpp>

class StateManager;

class State {
protected:
    std::weak_ptr<StateManager> manager;
    sf::RenderWindow &window;

    sf::Font mainFont;
public:
    explicit State(sf::RenderWindow &window);
    virtual ~State() = default;

    void SetManager(const std::weak_ptr<StateManager> &);

    virtual void ProcessEvents() = 0;
    virtual void Render() = 0;
    virtual void Update() = 0;
};

#endif // PACMAN_STATE_H
