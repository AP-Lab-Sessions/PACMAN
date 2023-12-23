//

#ifndef PACMAN_GAMEOVERSTATE_H
#define PACMAN_GAMEOVERSTATE_H

#include "State/State.h"
#include "Game/Widgets/TextWidget/TextWidget.h"

/**
 * @brief The state where the player used all of his lives and died.
 */
class GameOverState : public State {
protected:
    TextWidget description, goToMenu;
public:
    explicit GameOverState(const std::weak_ptr<sf::RenderWindow> &window);

    void ProcessEvents(const sf::Event &event) override;
    void Render() override;
    void Update() override;
};

#endif // PACMAN_GAMEOVERSTATE_H
