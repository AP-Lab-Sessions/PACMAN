//

#include "StopWatch.h"

std::shared_ptr<PMLogic::Helper::StopWatch> PMLogic::Helper::StopWatch::instance {nullptr};

std::shared_ptr<PMLogic::Helper::StopWatch> PMLogic::Helper::StopWatch::GetInstance() {
    if(instance == nullptr) {
        std::shared_ptr<Helper::StopWatch> createdInstance{new Helper::StopWatch()};
        instance = createdInstance;
    }
    return instance;
}
PMLogic::Helper::StopWatch::StopWatch() {
    startTime = std::chrono::high_resolution_clock::now();
    prevTime = startTime;
}
void PMLogic::Helper::StopWatch::Tick() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    deltaTime = std::chrono::duration<float>(currentTime - prevTime).count();
    prevTime = currentTime;
}

float PMLogic::Helper::StopWatch::GetDeltaTime() const {
    return deltaTime;
}