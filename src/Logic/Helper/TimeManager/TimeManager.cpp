//

#include "TimeManager.h"

PMGame::Logic::Helper::Timer::Timer(const std::function<void()>& callback, const float& duration)
    : callback(callback), duration(duration) {}

PMGame::Logic::Helper::StopWatch::StopWatch()
    : isPaused(false), startTime(std::chrono::steady_clock::now()), capturedTime(std::chrono::steady_clock::now()) {}

void PMGame::Logic::Helper::StopWatch::Start() {
    isPaused = false;
    startTime = std::chrono::steady_clock::now();
}

float PMGame::Logic::Helper::StopWatch::GetCurrentTime() {
    auto captured = isPaused ? capturedTime : std::chrono::steady_clock::now();
    return std::chrono::duration<float>(captured - startTime).count();
}

void PMGame::Logic::Helper::StopWatch::Pause() {
    if (!isPaused) {
        isPaused = true;
        capturedTime = std::chrono::steady_clock::now();
    }
}

void PMGame::Logic::Helper::StopWatch::Resume() {
    if (isPaused) {
        isPaused = false;
        startTime += std::chrono::steady_clock::now() - capturedTime;
    }
}

bool PMGame::Logic::Helper::StopWatch::GetIsPaused() const { return isPaused; }

void PMGame::Logic::Helper::TimeManager::Pause() {
    stopWatch->Pause();
    for (auto iter = stopWatches.begin(); iter != stopWatches.end(); iter++) {
        if (!iter->expired()) {
            iter->lock()->Pause();
        } else
            iter = stopWatches.erase(iter);
    }
}

PMGame::Logic::Helper::TimeManager::TimeManager() : deltaTime(0.0) {}
void PMGame::Logic::Helper::TimeManager::Tick() {
    if (!stopWatch)
        stopWatch = std::make_unique<PMGame::Logic::Helper::StopWatch>();
    if (stopWatch->GetIsPaused()) {
        stopWatch->Resume();
        for (auto iter = stopWatches.begin(); iter != stopWatches.end(); iter++) {
            if (!iter->expired()) {
                iter->lock()->Resume();
            } else
                iter = stopWatches.erase(iter);
        }
    }
    deltaTime = stopWatch->GetCurrentTime();
    stopWatch->Start();

    for (auto timerIter = timers.begin(); timerIter != timers.end(); timerIter++) {
        if (!timerIter->expired()) {
            timerIter->lock()->duration -= deltaTime;
            if (timerIter->lock()->duration <= 0) {
                timerIter->lock()->callback();
                timerIter = timers.erase(timerIter);
            }
        } else
            timerIter = timers.erase(timerIter);
    }
}

float PMGame::Logic::Helper::TimeManager::GetDeltaTime() const { return deltaTime; }

void PMGame::Logic::Helper::TimeManager::AddTimer(const std::weak_ptr<PMGame::Logic::Helper::Timer>& timer) {
    timers.push_back(timer);
}
void PMGame::Logic::Helper::TimeManager::AddStopWatch(
    const std::weak_ptr<PMGame::Logic::Helper::StopWatch>& stopWatchArg) {
    stopWatches.push_back(stopWatchArg);
}