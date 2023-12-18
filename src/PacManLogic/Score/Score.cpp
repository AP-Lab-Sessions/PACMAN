//

#include "Score.h"
#include "Helper/DeltaTime/DeltaTime.h"
#include "Score/Scoreboard/Scoreboard.h"

void PMLogic::Score::StartTimedDecrease() {
    const std::function<void()> callback = [&]() {
        DecreaseScore(5);
        StartTimedDecrease();
    };
    scoreTimer = std::make_shared<PMLogic::Helper::Timer>(callback, 2.5f);
    PMLogic::Helper::DeltaTime::GetInstance().lock()->AddTimer(scoreTimer);
    stopWatch->Start();
}

PMLogic::Score::Score() :  stopWatch(std::make_shared<Helper::StopWatch>()), currentScore(0){
    StartTimedDecrease();
    PMLogic::Helper::DeltaTime::GetInstance().lock()->AddStopWatch(stopWatch);
}

PMLogic::Score::~Score() {
    const auto &scoreboard = PMLogic::Scoreboard::GetInstance().lock();
    scoreboard->AddScore(currentScore);
    scoreboard->SaveHighScore();
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
    const int divider = (stopWatch->GetCurrentTime() <= 1.0f) ? 1 : static_cast<int>(stopWatch->GetCurrentTime());
    IncreaseScore(eventData.reward/divider);
    stopWatch->Start();
}