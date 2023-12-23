//

#include "Scoreboard.h"
#include "lib/json.hpp"
#include <fstream>
#include <iostream>

using nlohmann::json;

PMLogic::Scoreboard::Scoreboard() {
    try {
        std::ifstream highScoreInput(HIGHSCORE_PATH);
        // If high score file exists => load it
        if (!highScoreInput.fail()) {
            json j = json::parse(highScoreInput);
            // Even if highScore contains more than 5 ints we will store the first 5.
            highScore = j["highScore"].get<std::set<int>>();
        } else
            std::cerr << "No highscore file found\n";
    } catch (const std::exception& exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
    }
}

std::array<int, 5> PMLogic::Scoreboard::GetHighScore() const {
    std::array<int, 5> result{};
    unsigned int i{0};
    for (auto iter = highScore.rbegin(); iter != highScore.rend() && std::distance(highScore.rbegin(), iter) < 5;
         iter++) {
        result.at(i) = *iter;
        i++;
    }
    return result;
}

void PMLogic::Scoreboard::SaveHighScore() const {
    try {
        std::ofstream file(HIGHSCORE_PATH);
        json j;
        j["highScore"] = GetHighScore();
        file << j;
    } catch (const std::exception& exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
    }
}

void PMLogic::Scoreboard::AddScore(const int& score) { highScore.insert(score); }