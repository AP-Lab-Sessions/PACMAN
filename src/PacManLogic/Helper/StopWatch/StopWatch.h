//

#ifndef PACMAN_STOPWATCH_H
#define PACMAN_STOPWATCH_H

#include "PMLogic.h"
#include <memory>
#include <chrono>


/**
 * @brief A Singleton helper class that keeps the difference in time between the tick and delta time
 */
class PMLogic::Helper::StopWatch {
private:
    StopWatch();
    static std::shared_ptr<PMLogic::Helper::StopWatch> instance;

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> prevTime;
    float deltaTime;
public:
    /**
     * @brief Make the assignment operator deleted
     */
    void operator=(const PMLogic::Helper::StopWatch &) = delete;
    /**
     * @brief Make the copy constructor deleted
     */
    StopWatch(PMLogic::Helper::StopWatch &) = delete;

    /**
     * @brief Gets the single instance of the class
     * @return The pointer to the instance
     */
    static std::shared_ptr<PMLogic::Helper::StopWatch> GetInstance();

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
