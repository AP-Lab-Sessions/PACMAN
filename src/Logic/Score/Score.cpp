//

#include "Score.h"
#include "Helper/TimeManager/TimeManager.h"
#include "Score/Scoreboard/Scoreboard.h"

void PMGame::Logic::Score::StartTimedDecrease() {
    const std::function<void()> callback = [&]() {
        DecreaseScore(5);
        StartTimedDecrease();
    };
    scoreTimer = std::make_shared<PMGame::Logic::Helper::Timer>(callback, 2.5f);
    PMGame::Logic::Helper::TimeManager::GetInstance().lock()->AddTimer(scoreTimer);
    stopWatch->Start();
}

PMGame::Logic::Score::Score() : stopWatch(std::make_shared<Helper::StopWatch>()), currentScore(0) {
    StartTimedDecrease();
    PMGame::Logic::Helper::TimeManager::GetInstance().lock()->AddStopWatch(stopWatch);
}

PMGame::Logic::Score::~Score() {
    const auto& scoreboard = PMGame::Logic::Scoreboard::GetInstance().lock();
    scoreboard->AddScore(currentScore);
    scoreboard->SaveHighScore();
}

int PMGame::Logic::Score::GetScore() const { return currentScore; }

void PMGame::Logic::Score::IncreaseScore(const int& amount) { currentScore += amount; }

void PMGame::Logic::Score::DecreaseScore(const int& amount) {
    currentScore = (currentScore - amount < 0) ? 0 : currentScore - amount;
}

void PMGame::Logic::Score::Update(const EntityCollectedEvent& eventData) {
    const int divider = (stopWatch->GetCurrentTime() <= 1.0f) ? 1 : static_cast<int>(stopWatch->GetCurrentTime());
    IncreaseScore(eventData.reward / divider);
    stopWatch->Start();
}