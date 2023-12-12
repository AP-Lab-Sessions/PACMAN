//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include <SFML/Graphics.hpp>
#include "State/StateManager/StateManager.h"
#include "PacManLogic/Coordinate/Coordinate.h"

class Game {
protected:
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<StateManager> stateManager;

    sf::View view;

    const unsigned int width,height;

    sf::RectangleShape background;

    void Update();
    void Render();
    void ProcessEvents();
public:
    Game(const unsigned int &width, const unsigned int &height);
    void Run();
};

#endif // PACMAN_GAME_H
