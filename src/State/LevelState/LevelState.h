//

#ifndef INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H
#define INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H

#include "State/State.h"

class LevelState : public State {
protected:
    sf::View view;
public:
    explicit LevelState(sf::RenderWindow &window);

    void ProcessEvents() override;
    void Render() override;
    void Update() override;
};


#endif //INC_2023_PROJECT_MAGNUSTYMOTEUS_LEVELSTATE_H
