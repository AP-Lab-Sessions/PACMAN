//

#include "State.h"

void State::SetManager(const std::weak_ptr<StateManager>& managerArg) { manager = managerArg; }

State::State(const std::weak_ptr<sf::RenderWindow>& window) : window(window) {
    mainFont.loadFromFile("assets/fonts/Pacmania.otf");
    secondaryFont.loadFromFile("assets/fonts/Emulogic.ttf");
}