//

#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "State/State.h"
#include "Game/Assets.h"

class MenuState : public State {
public:
    void Run(sf::RenderWindow &window) override;
};

#endif // PACMAN_MENUSTATE_H
