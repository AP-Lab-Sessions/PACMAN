//

#include "LevelState.h"

#include "EntityFactory/EntityFactory.h"
#include "Helper/TimeManager/TimeManager.h"
#include "View/State/GameOverState/GameOverState.h"
#include "View/State/PausedState/PausedState.h"
#include "View/StateManager/StateManager.h"

PMGame::View::LevelState::LevelState(const std::weak_ptr<sf::RenderWindow>& window)
    : State(window), score(TextWidget("SCORE: ", secondaryFont, sf::Color::Yellow, 30, {0, 0})),
      lives(TextWidget("LIVES: ", secondaryFont, sf::Color::Yellow, 30,
                       {window.lock()->getDefaultView().getSize().x - 250, 0})) {
    std::unique_ptr<PMGame::Logic::AbstractFactory> factory{std::make_unique<EntityFactory>(views, window)};
    world = std::make_unique<PMGame::Logic::World>(factory);

    score.text.setOrigin(0, 0);
    lives.text.setOrigin(0, 0);
}

void PMGame::View::LevelState::Update() {
    std::weak_ptr<PMGame::Logic::Helper::TimeManager> stopWatch = PMGame::Logic::Helper::TimeManager::GetInstance();
    stopWatch.lock()->Tick();
    if (!world->GetLives()) {
        PMGame::Logic::Helper::TimeManager::GetInstance().lock()->Pause();
        std::unique_ptr<State> newState{new GameOverState(window)};
        manager.lock()->PushState(newState);
    } else {
        world->Update();
        score.text.setString("SCORE: " + std::to_string(world->GetScore()));
        lives.text.setString("LIVES: " + std::to_string(world->GetLives()));
    }
}

void PMGame::View::LevelState::Render() {
    const auto& renderWindow = window.lock();
    for (const auto& currentView : views) {
        currentView->Render();
    }
    renderWindow->draw(score.text);
    renderWindow->draw(lives.text);
}

void PMGame::View::LevelState::ProcessEvents(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Key::A: {}
        case sf::Keyboard::Key::Left: {
            world->SetPlayerDirection(PMGame::Logic::Coordinate2D::Direction_Left);
            break;
        }
        case sf::Keyboard::Key::D: {}
        case sf::Keyboard::Key::Right: {
            world->SetPlayerDirection(PMGame::Logic::Coordinate2D::Direction_Right);
            break;
        }
        case sf::Keyboard::Key::W: {}
        case sf::Keyboard::Key::Up: {
            world->SetPlayerDirection(PMGame::Logic::Coordinate2D::Direction_Up);
            break;
        }
        case sf::Keyboard::Key::S: {}
        case sf::Keyboard::Key::Down: {
            world->SetPlayerDirection(PMGame::Logic::Coordinate2D::Direction_Down);
            break;
        }
        case sf::Keyboard::Key::Escape: {
            PMGame::Logic::Helper::TimeManager::GetInstance().lock()->Pause();
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