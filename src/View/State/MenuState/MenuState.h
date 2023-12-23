//

#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "View/State/State.h"
#include "View/Widgets/TextWidget/TextWidget.h"

namespace PMGame::View {
/**
 * @brief The main menu of the game.
 */
class MenuState : public State {
protected:
    TextWidget title, play, quit, highScore;

public:
    explicit MenuState(const std::weak_ptr<sf::RenderWindow>& window);

    void ProcessEvents(const sf::Event& event) override;
    void Render() override;
    void Update() override;
};
} // namespace PMGame::View
#endif // PACMAN_MENUSTATE_H
