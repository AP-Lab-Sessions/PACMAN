//

#include "Score.h"

PMLogic::Score::Score() : currentScore(0) {}

void PMLogic::Score::Update(const PacMan& pacMan) {

}

int PMLogic::Score::GetScore() const {
    return currentScore;
}

void PMLogic::Score::IncreaseScore(const int& amount) {
    currentScore += amount;
}

void PMLogic::Score::DecreaseScore(const int& amount) {
    if(currentScore-amount <= 0) currentScore = 0;
    else currentScore -= amount;
}