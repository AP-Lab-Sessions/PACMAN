//

#include "LevelState.h"

#include "EntityFactory/EntityFactory.h"
#include "Helper/DeltaTime/DeltaTime.h"
#include "State/PausedState/PausedState.h"
#include "State/GameOverState/GameOverState.h"
#include "State/StateManager/StateManager.h"

LevelState::LevelState(const std::weak_ptr<sf::RenderWindow> &window) : State(window),
score(TextWidget("SCORE: ", secondaryFont, sf::Color::Yellow, 30, {0, 0})),
lives(TextWidget("LIVES: ", secondaryFont, sf::Color::Yellow, 30, {window.lock()->getDefaultView().getSize().x-250, 0}))
{
    std::unique_ptr<PMLogic::AbstractFactory> factory {std::make_unique<EntityFactory>(views, window)};
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
    std::weak_ptr<PMLogic::Helper::DeltaTime> stopWatch = PMLogic::Helper::DeltaTime::GetInstance();
    stopWatch.lock()->Tick();
}

void LevelState::Render() {
    const auto &renderWindow = window.lock();
    for(const auto &currentView : views) {
        currentView->Render();
    }
    renderWindow->draw(score.text);
    renderWindow->draw(lives.text);
}

void LevelState::ProcessEvents(const sf::Event &event) {
    if(event.type == sf::Event::KeyPressed) {
        switch(event.key.code) {
            case sf::Keyboard::Key::Left: {
                world->SetPlayerDirection(Coordinate2D::Direction_Left);
                break;
            }
            case sf::Keyboard::Key::Right: {
                world->SetPlayerDirection(Coordinate2D::Direction_Right);
                break;
            }
            case sf::Keyboard::Key::Up: {
                world->SetPlayerDirection(Coordinate2D::Direction_Up);
                break;
            }
            case sf::Keyboard::Key::Down: {
                world->SetPlayerDirection(Coordinate2D::Direction_Down);
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