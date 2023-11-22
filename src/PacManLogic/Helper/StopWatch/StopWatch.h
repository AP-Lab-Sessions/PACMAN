//

#ifndef PACMAN_STOPWATCH_H
#define PACMAN_STOPWATCH_H

#include "PMLogic.h"
#include <memory>
#include <chrono>

using namespace PMLogic;

/**
 * @brief A Singleton helper class that keeps the difference in time between the tick and delta time
 */
class Helper::StopWatch {
private:
    StopWatch();
    static std::shared_ptr<StopWatch> instance;

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> prevTime;
    float deltaTime;
public:
    /**
     * @brief Make the assignment operator deleted
     */
    void operator=(const Helper::StopWatch &) = delete;
    /**
     * @brief Make the copy constructor deleted
     */
    StopWatch(Helper::StopWatch &) = delete;

    /**
     * @brief Gets the single instance of the class
     * @return The pointer to the instance
     */
    static std::shared_ptr<StopWatch> GetInstance();

    /**
     * @brief
     */
     void Tick();

    /**
     * @brief
     * @return deltaTime
     */
     float GetDeltaTime() const;
};

#endif // PACMAN_STOPWATCH_H
