//

#ifndef PACMAN_PAUSEDSTATE_H
#define PACMAN_PAUSEDSTATE_H

#include "Game/Widgets/ButtonWidget/ButtonWidget.h"
#include "State/State.h"

#include <memory>

class PausedState : public State {
protected:
    ButtonWidget description, resume,goToMenu;
        public:
    explicit PausedState(const std::weak_ptr<sf::RenderWindow> &window);

    void ProcessEvents(const sf::Event &event) override;
    void Render() override;
    void Update() override;
};

#endif // PACMAN_PAUSEDSTATE_H
