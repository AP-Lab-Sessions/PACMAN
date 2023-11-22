//

#include "StopWatch.h"

std::shared_ptr<Helper::StopWatch> Helper::StopWatch::instance {nullptr};

std::shared_ptr<Helper::StopWatch> Helper::StopWatch::GetInstance() {
    if(instance == nullptr) {
        std::shared_ptr<Helper::StopWatch> createdInstance{new Helper::StopWatch()};
        instance = createdInstance;
    }
    return instance;
}
Helper::StopWatch::StopWatch() {
    startTime = std::chrono::high_resolution_clock::now();
    prevTime = startTime;
}
void Helper::StopWatch::Tick() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    deltaTime = std::chrono::duration<float>(currentTime - prevTime).count();
    prevTime = currentTime;
}

float Helper::StopWatch::GetDeltaTime() const {
    return deltaTime;
}