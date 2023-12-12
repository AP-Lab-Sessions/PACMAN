//

#include "LevelState.h"
#include "EntityFactory/EntityFactory.h"

LevelState::LevelState(const std::weak_ptr<sf::RenderWindow> &window) : State(window),
views(new std::vector<std::shared_ptr<IEntityObserver>>())
{
    std::unique_ptr<PMLogic::AbstractFactory> factory {std::make_unique<EntityFactory>(views, window)};
    world = std::make_unique<PMLogic::World>(factory);
}

void LevelState::Update() {
    world->Update();
}

void LevelState::Render() {
    for(const auto &currentEntityObserver : *views) {
        currentEntityObserver->Render();
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