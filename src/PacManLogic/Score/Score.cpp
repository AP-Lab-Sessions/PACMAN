//

#include "Score.h"
#include "Helper/StopWatch/StopWatch.h"

void PMLogic::Score::StartTimedDecrease() {
    const std::function<void()> callback = [&]() {
        DecreaseScore(10);
        StartTimedDecrease();
    };
    scoreTimer = std::make_shared<PMLogic::Helper::Timer>(callback, 5.0f);
    PMLogic::Helper::StopWatch::GetInstance().lock()->AddTimer(scoreTimer);
}

PMLogic::Score::Score() : currentScore(0){
    StartTimedDecrease();
}

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
}