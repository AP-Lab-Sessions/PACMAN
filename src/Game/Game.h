//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include "IObserver/IObserver.h"
#include "EntityFactory/EntityFactory.h"
#include "State/StateManager/StateManager.h"

#include <SFML/Graphics.hpp>

class Game {
protected:
    const std::shared_ptr<std::vector<std::shared_ptr<PMLogic::IObserver>>> views;
    std::unique_ptr<sf::RenderWindow> window;
    std::shared_ptr<StateManager> stateManager;

    void Update();
    void Render();
public:
    Game();
    void Run();
};

#endif // PACMAN_GAME_H
