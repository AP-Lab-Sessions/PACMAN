//

#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "Game/Widgets/TextWidget/TextWidget.h"
#include "State/State.h"

class MenuState : public State {
protected:
    TextWidget title, play, quit, highScore;

public:
    explicit MenuState(const std::weak_ptr<sf::RenderWindow> &window);

    void ProcessEvents(const sf::Event &event) override;
    void Render() override;
    void Update() override;
};

#endif // PACMAN_MENUSTATE_H
