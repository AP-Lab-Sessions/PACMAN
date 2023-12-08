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

MenuState::MenuState(sf::RenderWindow &window) : State(window), view(sf::View(sf::FloatRect(0,0,800,600))),
title(Button("PACMAN", mainFont, sf::Color::Yellow, 75, {static_cast<float>(window.getSize().x)/2.0f, 50})),
play(Button("PLAY", mainFont, sf::Color::Yellow, 45, {static_cast<float>(window.getSize().x)/2.0f, 250})),
quit(Button("QUIT", mainFont, sf::Color::Yellow, 45, {static_cast<float>(window.getSize().x)/2.0f, 350})),
highScore(Button(getHighScoreStr(), mainFont, sf::Color::Yellow, 30,
                 {static_cast<float>(window.getSize().x-100), static_cast<float>(window.getSize().y-100)}))
{

}

void MenuState::Update() {

}

void MenuState::ProcessEvents() {
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
        if(event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if(play.IsClicked(mouse)) {
                    std::unique_ptr<State> newState {new LevelState(window)};
                    manager.lock()->PushState(newState);
                }
                if(quit.IsClicked(mouse)) {
                    window.close();
                }
            }
        }
    }
}

void MenuState::Render() {
    window.draw(title.text);
    window.draw(play.text);
    window.draw(quit.text);
    window.draw(highScore.text);
}