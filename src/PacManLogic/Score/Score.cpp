//

#include "Score.h"
#include <iostream>
#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

PMLogic::Score::Score() : currentScore(0){}

int PMLogic::Score::GetScore() const {
    return currentScore;
}

void PMLogic::Score::IncreaseScore(const int& amount) {
    currentScore += amount;
}

void PMLogic::Score::DecreaseScore(const int& amount) {
    currentScore = (currentScore-amount < 0) ? 0 : currentScore - amount;
}

void PMLogic::Score::Update(const EntityCollectedEvent &eventData) {
    IncreaseScore(eventData.reward);
    std::cout << "current score: " << currentScore << std::endl;
}