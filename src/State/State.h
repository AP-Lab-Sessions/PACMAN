//

#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H

#include <memory>
#include <SFML/Graphics.hpp>

class StateManager;

/**
 * @brief The state interface.
 */
class State {
protected:
    /**
     * @brief The state manager.
     */
    std::weak_ptr<StateManager> manager;
    /**
     * @brief The render window.
     */
    std::weak_ptr<sf::RenderWindow> window;

    /**
     * @brief The main (non-pixelated) font of the game.
     */
    sf::Font mainFont;
    /**
     * @brief The secondary (pixelated) font of the game.
     */
    sf::Font secondaryFont;
public:
    /**
     *
     * @param window The render window.
     */
    explicit State(const std::weak_ptr<sf::RenderWindow> &window);
    virtual ~State() = default;

    /**
     * @brief Sets the State manager.
     */
    void SetManager(const std::weak_ptr<StateManager> &);

    /**
     * @brief Processes events of the state.
     * @param event
     */
    virtual void ProcessEvents(const sf::Event &event) = 0;
    /**
     * @brief Renders the contents of the state.
     */
    virtual void Render() = 0;
    /**
     * @brief Updates the contents of the state.
     */
    virtual void Update() = 0;
};

#endif // PACMAN_STATE_H
