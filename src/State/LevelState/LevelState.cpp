//

#include "LevelState.h"
#include "EntityFactory/EntityFactory.h"

LevelState::LevelState(const std::weak_ptr<sf::RenderWindow> &window) : State(window),
renderCallbacks(new std::vector<std::function<void()>>())
{
    std::unique_ptr<PMLogic::AbstractFactory> factory {std::make_unique<EntityFactory>(renderCallbacks, window)};
    world = std::make_unique<PMLogic::World>(factory);
}

void LevelState::Update() {
    world->Update();
}

void LevelState::Render() {
    for(const auto &currentRenderCallback : *renderCallbacks) {
        if(currentRenderCallback) currentRenderCallback();
    }
}

void LevelState::ProcessEvents(const sf::Event &event) {
    if(event.type == sf::Event::KeyPressed) {
        switch(event.key.code) {
            case sf::Keyboard::Key::Left:
                world->SetPlayerDirection(Direction_Left);
                break;
            case sf::Keyboard::Key::Right:
                world->SetPlayerDirection(Direction_Right);
                break;
            case sf::Keyboard::Key::Up:
                world->SetPlayerDirection(Direction_Up);
                break;
            case sf::Keyboard::Key::Down:
                world->SetPlayerDirection(Direction_Down);
                break;
            default:
                break;
        }
    }
}