//

#include "LevelState.h"

#include "EntityFactory/EntityFactory.h"
#include "Helper/DeltaTime/DeltaTime.h"
#include "State/PausedState/PausedState.h"
#include "State/GameOverState/GameOverState.h"
#include "State/StateManager/StateManager.h"

LevelState::LevelState(const std::weak_ptr<sf::RenderWindow> &window) : State(window),
renderCallbacks(new std::vector<std::function<void()>>()),
score(TextWidget("SCORE: ", secondaryFont, sf::Color::Yellow, 30, {0, 0})),
lives(TextWidget("LIVES: ", secondaryFont, sf::Color::Yellow, 30, {window.lock()->getDefaultView().getSize().x-250, 0}))
{
    std::unique_ptr<PMLogic::AbstractFactory> factory {std::make_unique<EntityFactory>(renderCallbacks, window)};
    world = std::make_unique<PMLogic::World>(factory);

    score.text.setOrigin(0, 0);
    lives.text.setOrigin(0, 0);
}

void LevelState::Update() {
    if(!world->GetLives()) {
        PMLogic::Helper::DeltaTime::GetInstance().lock()->Pause();
        std::unique_ptr<State> newState{new GameOverState(window)};
        manager.lock()->PushState(newState);
    }
    else {
        world->Update();
        score.text.setString("SCORE: " + std::to_string(world->GetScore()));
        lives.text.setString("LIVES: " + std::to_string(world->GetLives()));
    }
}

void LevelState::Render() {
    const auto &renderWindow = window.lock();
    for(const auto &currentRenderCallback : *renderCallbacks) {
        if(currentRenderCallback) currentRenderCallback();
    }
    renderWindow->draw(score.text);
    renderWindow->draw(lives.text);
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
                PMLogic::Helper::DeltaTime::GetInstance().lock()->Pause();
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