//

#include "StopWatch.h"

#include <iostream>


PMLogic::Helper::Timer::Timer(const std::function<void()>& callback, const float& duration)
    : callback(callback), duration(duration) {}

void PMLogic::Helper::StopWatch::Reset() {
    isPaused = true;
    deltaTime = std::chrono::duration<float>(startTime - prevTime).count();
}

std::shared_ptr<PMLogic::Helper::StopWatch> PMLogic::Helper::StopWatch::instance {nullptr};

std::weak_ptr<PMLogic::Helper::StopWatch> PMLogic::Helper::StopWatch::GetInstance() {
    if(instance == nullptr) {
        std::shared_ptr<Helper::StopWatch> createdInstance{new Helper::StopWatch()};
        instance = createdInstance;
    }
    return instance;
}
PMLogic::Helper::StopWatch::StopWatch() {
    isPaused = false;
    startTime = std::chrono::high_resolution_clock::now();
    prevTime = startTime;
}
void PMLogic::Helper::StopWatch::Tick() {
    if(isPaused) {
        startTime = std::chrono::high_resolution_clock::now();
        prevTime = startTime;
        isPaused = false;
    }
    auto currentTime = std::chrono::high_resolution_clock::now();
    deltaTime = std::chrono::duration<float>(currentTime - prevTime).count();
    prevTime = currentTime;

    for(auto timerIter = timers.begin(); timerIter != timers.end(); timerIter++) {
        if(!timerIter->expired()) {
            timerIter->lock()->duration -= deltaTime;
            if (timerIter->lock()->duration <= 0) {
                timerIter->lock()->callback();
                timerIter = timers.erase(timerIter);
            }
        }
        else timerIter = timers.erase(timerIter);
    }
}

float PMLogic::Helper::StopWatch::GetDeltaTime() const {
    return deltaTime;
}

void PMLogic::Helper::StopWatch::AddTimer(const std::weak_ptr<PMLogic::Helper::Timer> &timer) {
    timers.push_back(timer);
}