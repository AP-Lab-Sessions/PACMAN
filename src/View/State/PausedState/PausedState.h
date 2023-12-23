//

#ifndef PACMAN_PAUSEDSTATE_H
#define PACMAN_PAUSEDSTATE_H

#include "View/State/State.h"
#include "View/Widgets/TextWidget/TextWidget.h"

namespace PMGame::View {
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
} // namespace PMGame::View
#endif // PACMAN_PAUSEDSTATE_H
