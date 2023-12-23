//

#ifndef INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H
#define INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H

#include "Logic/World/World.h"
#include "View/EntityView/EntityView.h"
#include "View/State/State.h"
#include "View/Widgets/TextWidget/TextWidget.h"

namespace PMGame::View {
/**
 * @brief The game level.
 */
class LevelState : public State {
protected:
    /**
     * @brief Entity views
     */
    std::vector<std::shared_ptr<EntityView>> views;
    /**
     * @brief The world
     */
    std::unique_ptr<PMGame::Logic::World> world;
    TextWidget score, lives;

public:
    explicit LevelState(const std::weak_ptr<sf::RenderWindow>& window);

    void ProcessEvents(const sf::Event& event) override;
    void Render() override;
    void Update() override;
};
} // namespace PMGame::View
#endif // INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H
