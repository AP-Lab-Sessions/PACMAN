//

#include "MenuState.h"
#include "State/LevelState/LevelState.h"
#include "State/StateManager/StateManager.h"
#include "PacManLogic/Score/Scoreboard/Scoreboard.h"

std::string getHighScoreStr() {
    std::string highScoreStr = "HIGH SCORE: \n";
    const std::array<int, 5> &highScores = PMLogic::Scoreboard::GetInstance().lock()->GetHighScore();
    for(unsigned int i=0;i<highScores.size();i++) {
        if(highScores[i]) highScoreStr += std::to_string(i+1)+": "+std::to_string(highScores[i])+"\n";
    }
    return highScoreStr;
}


MenuState::MenuState(const std::weak_ptr<sf::RenderWindow> &window) : State(window),
title(ButtonWidget("PACMAN", mainFont, sf::Color::Yellow, 75, {sf::Vector2f(window.lock()->getSize()).x/2.0f, 50})),
play(ButtonWidget("PLAY", mainFont, sf::Color::Yellow, 45, {sf::Vector2f(window.lock()->getSize()).x/2.0f, 250})),
quit(ButtonWidget("QUIT", mainFont, sf::Color::Yellow, 45, {sf::Vector2f(window.lock()->getSize()).x/2.0f, 350})),
highScore(ButtonWidget(getHighScoreStr(), secondaryFont, sf::Color::Yellow, 20,
                 {200, (sf::Vector2f(window.lock()->getSize()).y)-100}))
{

}

void MenuState::Update() {}

void MenuState::ProcessEvents(const sf::Event &event) {
    if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = window.lock()->mapPixelToCoords(sf::Mouse::getPosition(*window.lock()));
            if(play.IsClicked(mouse)) {
                std::unique_ptr<State> newState {new LevelState(window)};
                manager.lock()->PushState(newState);
            }
            if(quit.IsClicked(mouse)) {
                window.lock()->close();
            }
        }
    }
}

void MenuState::Render() {
    sf::RenderWindow &renderWindow = (*window.lock());
    renderWindow.draw(title.text);
    renderWindow.draw(play.text);
    renderWindow.draw(quit.text);
    renderWindow.draw(highScore.text);
}