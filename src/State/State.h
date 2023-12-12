//

#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H

#include <memory>
#include <SFML/Graphics.hpp>

class StateManager;

class State {
protected:
    std::weak_ptr<StateManager> manager;
    std::weak_ptr<sf::RenderWindow> window;

    sf::Font mainFont;
    sf::Font secondaryFont;
public:
    explicit State(const std::weak_ptr<sf::RenderWindow> &window);
    virtual ~State() = default;

    void SetManager(const std::weak_ptr<StateManager> &);

    virtual void ProcessEvents(const sf::Event &event) = 0;
    virtual void Render() = 0;
    virtual void Update() = 0;
};

#endif // PACMAN_STATE_H
