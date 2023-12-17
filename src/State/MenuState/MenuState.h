//

#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "State/State.h"
#include "Game/Widgets/ButtonWidget/ButtonWidget.h"

#include <memory>

class MenuState : public State {
protected:
    ButtonWidget title, play, quit, highScore;

public:
    explicit MenuState(const std::weak_ptr<sf::RenderWindow> &window);

    void ProcessEvents(const sf::Event &event) override;
    void Render() override;
    void Update() override;
};

#endif // PACMAN_MENUSTATE_H
