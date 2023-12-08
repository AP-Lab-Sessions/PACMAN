//

#include "LevelState.h"

LevelState::LevelState(sf::RenderWindow &window) : State(window) {

}

void LevelState::Update() {

}

void LevelState::Render() {

}

void LevelState::ProcessEvents() {
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::Resized) {
            view.setSize({
                                 static_cast<float>(event.size.width),
                                 static_cast<float>(event.size.height)
                         });
            window.setView(view);
        }
    }
}