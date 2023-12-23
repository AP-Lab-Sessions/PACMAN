//

#ifndef PACMAN_GAMEOVERSTATE_H
#define PACMAN_GAMEOVERSTATE_H

#include "View/State/State.h"
#include "View/Widgets/TextWidget/TextWidget.h"

namespace PMGame::View {
/**
 * @brief The state where the player used all of his lives and died.
 */
class GameOverState : public State {
protected:
    TextWidget description, goToMenu;

public:
    explicit GameOverState(const std::weak_ptr<sf::RenderWindow>& window);

    void ProcessEvents(const sf::Event& event) override;
    void Render() override;
    void Update() override;
};
} // namespace PMGame::View
#endif // PACMAN_GAMEOVERSTATE_H
