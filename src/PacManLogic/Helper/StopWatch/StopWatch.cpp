//

#include "StopWatch.h"

std::shared_ptr<PMLogic::Helper::StopWatch> PMLogic::Helper::StopWatch::instance {nullptr};

std::weak_ptr<PMLogic::Helper::StopWatch> PMLogic::Helper::StopWatch::GetInstance() {
    if(instance == nullptr) {
        std::shared_ptr<Helper::StopWatch> createdInstance{new Helper::StopWatch()};
        instance = createdInstance;
    }
    return instance;
}
PMLogic::Helper::StopWatch::StopWatch() {
    startTime = std::chrono::high_resolution_clock::now();
    prevTime = startTime;
    deltaTime = std::chrono::duration<float>(startTime - prevTime).count();
}
void PMLogic::Helper::StopWatch::Tick() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    deltaTime = std::chrono::duration<float>(currentTime - prevTime).count();
    prevTime = currentTime;
}

float PMLogic::Helper::StopWatch::GetDeltaTime() const {
    return deltaTime;
}