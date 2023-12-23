//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "PacManLogic/Coordinate/Coordinate.h"
#include "State/StateManager/StateManager.h"
#include <SFML/Graphics.hpp>

/**
 * @brief The PacMan Game class which holds the view aspect of the game and the logic aspect.
 */
class Game {
protected:
    /**
     * @brief The render window.
     */
    std::shared_ptr<sf::RenderWindow> window;
    /**
     * @brief The state manager.
     */
    std::shared_ptr<StateManager> stateManager;

    /**
     * @brief The view of the render window.
     */
    sf::View view;

    /**
     * @brief The outline of the render window.
     */
    sf::RectangleShape outline;

    /**
     * @brief Updates the game by calling the update of the state manager.
     */
    void Update();
    /**
     * @brief Renders the game by drawing an outline of the game's window and calling the render of state manager.
     */
    void Render();
    /**
     * @brief Processes the input of the game like mouse and keyboard.
     */
    void ProcessEvents();

public:
    /**
     *
     * @param width Width of the view and initial width of the render window
     * @param height Height of the view and initial height of the render window
     */
    Game(const unsigned int& width, const unsigned int& height);

    /**
     * @brif Runs the entire game (calls all the above methods)
     */
    void Run();
};

#endif // PACMAN_GAME_H
