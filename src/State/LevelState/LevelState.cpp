//

#include "LevelState.h"

#include "State/StateManager/StateManager.h"
#include "State/PausedState/PausedState.h"
#include "EntityFactory/EntityFactory.h"
#include "Helper/StopWatch/StopWatch.h"


LevelState::LevelState(const std::weak_ptr<sf::RenderWindow> &window) : State(window),
renderCallbacks(new std::vector<std::function<void()>>()),
score(ButtonWidget("SCORE: ", secondaryFont, sf::Color::Yellow, 30, {0, 0}))
{
    std::unique_ptr<PMLogic::AbstractFactory> factory {std::make_unique<EntityFactory>(renderCallbacks, window)};
    world = std::make_unique<PMLogic::World>(factory);
    score.text.setOrigin(0, 0);
}

void LevelState::Update() {
   world->Update();
   score.text.setString("SCORE: "+std::to_string(world->GetScore()));
}

void LevelState::Render() {
    const auto &renderWindow = window.lock();
    for(const auto &currentRenderCallback : *renderCallbacks) {
        if(currentRenderCallback) currentRenderCallback();
    }
    renderWindow->draw(score.text);
}

void LevelState::ProcessEvents(const sf::Event &event) {
    if(event.type == sf::Event::KeyPressed) {
        switch(event.key.code) {
            case sf::Keyboard::Key::Left: {
                world->SetPlayerDirection(Direction_Left);
                break;
            }
            case sf::Keyboard::Key::Right: {
                world->SetPlayerDirection(Direction_Right);
                break;
            }
            case sf::Keyboard::Key::Up: {
                world->SetPlayerDirection(Direction_Up);
                break;
            }
            case sf::Keyboard::Key::Down: {
                world->SetPlayerDirection(Direction_Down);
                break;
            }
            case sf::Keyboard::Key::Escape: {
                PMLogic::Helper::StopWatch::GetInstance().lock()->Reset();
                std::unique_ptr<State> newState{new PausedState(window)};
                manager.lock()->PushState(newState);
                break;
            }
            default: {
                break;
            }
        }
    }
}