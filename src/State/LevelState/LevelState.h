//

#ifndef INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H
#define INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H

#include "EntityView/EntityView.h"
#include "Game/Widgets/TextWidget/TextWidget.h"
#include "PacManLogic/World/World.h"
#include "State/State.h"

class LevelState : public State {
protected:
    const std::shared_ptr<std::vector<std::function<void()>>> renderCallbacks;
    std::unique_ptr<PMLogic::World> world;
    TextWidget score, lives;
public:
    explicit LevelState(const std::weak_ptr<sf::RenderWindow> &window);

    void ProcessEvents(const sf::Event &event) override;
    void Render() override;
    void Update() override;
};


#endif //INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H
