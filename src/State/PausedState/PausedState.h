//

#ifndef PACMAN_PAUSEDSTATE_H
#define PACMAN_PAUSEDSTATE_H

#include "Game/Widgets/TextWidget/TextWidget.h"
#include "State/State.h"

/**
 * @brief State where the currently played level is paused.
 */
class PausedState : public State {
protected:
    TextWidget description, resume, goToMenu;

public:
    explicit PausedState(const std::weak_ptr<sf::RenderWindow>& window);

    void ProcessEvents(const sf::Event& event) override;
    void Render() override;
    void Update() override;
};

#endif // PACMAN_PAUSEDSTATE_H
