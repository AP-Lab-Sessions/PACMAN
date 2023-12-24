//

#include "MenuState.h"
#include "Logic/Score/Scoreboard/Scoreboard.h"
#include "View/State/LevelState/LevelState.h"
#include "View/StateManager/StateManager.h"

std::string getHighScoreStr() {
    std::string highScoreStr = "HIGH SCORE: \n";
    const std::array<int, 5>& highScores = PMGame::Logic::Scoreboard::GetInstance().lock()->GetHighScore();
    for (unsigned int i = 0; i < highScores.size(); i++) {
        if (highScores[i])
            highScoreStr += std::to_string(i + 1) + ": " + std::to_string(highScores[i]) + "\n";
    }
    return highScoreStr;
}

PMGame::View::MenuState::MenuState(const std::weak_ptr<sf::RenderWindow>& window)
    : State(window), title(TextWidget("PACMAN", mainFont, sf::Color::Yellow, 75,
                                      {sf::Vector2f(window.lock()->getSize()).x / 2.0f, 50})),
      play(TextWidget("PLAY", mainFont, sf::Color::Yellow, 45, {sf::Vector2f(window.lock()->getSize()).x / 2.0f, 250})),
      quit(TextWidget("QUIT", mainFont, sf::Color::Yellow, 45, {sf::Vector2f(window.lock()->getSize()).x / 2.0f, 350})),
      highScore(TextWidget(getHighScoreStr(), secondaryFont, sf::Color::Yellow, 20,
                           {200, (sf::Vector2f(window.lock()->getSize()).y) - 100})) {}

void PMGame::View::MenuState::Update() { highScore.text.setString(getHighScoreStr()); }

void PMGame::View::MenuState::ProcessEvents(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = window.lock()->mapPixelToCoords(sf::Mouse::getPosition(*window.lock()));
            if (play.IsClicked(mouse)) {
                std::unique_ptr<State> newState{new LevelState(window)};
                manager.lock()->PushState(newState);
            }
            if (quit.IsClicked(mouse)) {
                window.lock()->close();
            }
        }
    }
}

void PMGame::View::MenuState::Render() {
    sf::RenderWindow& renderWindow = (*window.lock());
    renderWindow.draw(title.text);
    renderWindow.draw(play.text);
    renderWindow.draw(quit.text);
    renderWindow.draw(highScore.text);
}