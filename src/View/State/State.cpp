//

#include "State.h"

void PMGame::View::State::SetManager(const std::weak_ptr<PMGame::View::StateManager>& managerArg) {
    manager = managerArg;
}

PMGame::View::State::State(const std::weak_ptr<sf::RenderWindow>& window) : window(window) {
    mainFont.loadFromFile("assets/fonts/Pacmania.otf");
    secondaryFont.loadFromFile("assets/fonts/Emulogic.ttf");
}