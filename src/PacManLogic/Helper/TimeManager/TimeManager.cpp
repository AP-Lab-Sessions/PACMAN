//

#include "TimeManager.h"

#include <iostream>

// TODO: fix stopwatch that changes itself for no reason
PMLogic::Helper::Timer::Timer(const std::function<void()>& callback, const float& duration)
    : callback(callback), duration(duration) {}

PMLogic::Helper::StopWatch::StopWatch()
    : isPaused(false), startTime(std::chrono::steady_clock::now()), capturedTime(std::chrono::steady_clock::now()) {}

void PMLogic::Helper::StopWatch::Start() {
    isPaused = false;
    startTime = std::chrono::steady_clock::now();
}

float PMLogic::Helper::StopWatch::GetCurrentTime() {
    auto captured = isPaused ? capturedTime : std::chrono::steady_clock::now();
    return std::chrono::duration<float>(captured - startTime).count();
}

void PMLogic::Helper::StopWatch::Pause() {
    if (!isPaused) {
        isPaused = true;
        capturedTime = std::chrono::steady_clock::now();
    }
}

void PMLogic::Helper::StopWatch::Resume() {
    if (isPaused) {
        isPaused = false;
        startTime += std::chrono::steady_clock::now() - capturedTime;
    }
}

bool PMLogic::Helper::StopWatch::GetIsPaused() const { return isPaused; }

void PMLogic::Helper::TimeManager::Pause() {
    stopWatch->Pause();
    for (auto iter = stopWatches.begin(); iter != stopWatches.end(); iter++) {
        if (!iter->expired()) {
            iter->lock()->Pause();
        } else
            iter = stopWatches.erase(iter);
    }
}

PMLogic::Helper::TimeManager::TimeManager() : deltaTime(0.0) {}
void PMLogic::Helper::TimeManager::Tick() {
    if (!stopWatch)
        stopWatch = std::make_unique<PMLogic::Helper::StopWatch>();
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

float PMLogic::Helper::TimeManager::GetDeltaTime() const { return deltaTime; }

void PMLogic::Helper::TimeManager::AddTimer(const std::weak_ptr<PMLogic::Helper::Timer>& timer) {
    timers.push_back(timer);
}
void PMLogic::Helper::TimeManager::AddStopWatch(const std::weak_ptr<PMLogic::Helper::StopWatch>& stopWatchArg) {
    stopWatches.push_back(stopWatchArg);
}