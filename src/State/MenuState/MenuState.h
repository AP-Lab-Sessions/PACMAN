//

#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "State/State.h"
#include "Game/Assets.h"
#include "Game/Widgets/Button/Button.h"

#include <memory>

class MenuState : public State {
protected:
    sf::View view;
    Button title, play, quit, highScore;

public:
    explicit MenuState(sf::RenderWindow &window);

    void ProcessEvents() override;
    void Render() override;
    void Update() override;
};

#endif // PACMAN_MENUSTATE_H
