//

#ifndef PACMAN_DELTATIME_H
#define PACMAN_DELTATIME_H

#include "PMLogic.h"

#include "Pattern/Singleton/Singleton.h"

#include <chrono>
#include <functional>
#include <list>


class PMLogic::Helper::Timer {
public:
    const std::function<void()> callback;
    float duration;

    Timer(const std::function<void()> &callback, const float &duration);
};

class PMLogic::Helper::StopWatch {
protected:
    bool isPaused;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime, capturedTime;
public:
    StopWatch();
    void Start();

    float GetCurrentTime();

    void Pause();

    void Resume();

    bool GetIsPaused() const;
};

/**
 * @brief A Singleton helper class that keeps the difference in time between the tick and delta time
 */
class PMLogic::Helper::DeltaTime : public PMLogic::Singleton<PMLogic::Helper::DeltaTime> {
protected:
    DeltaTime();

    float deltaTime;
    PMLogic::Helper::StopWatch stopWatch;

    std::list<std::weak_ptr<PMLogic::Helper::Timer>> timers;
    std::list<std::weak_ptr<PMLogic::Helper::StopWatch>> stopWatches;

public:
    /**
     * @brief
     */
    void Pause();

    /**
     * @brief
     */
     void Tick();

    /**
     * @brief
     * @return deltaTime
     */
     float GetDeltaTime() const;

     /**
      * @brief
      * @param callBack
      * @param duration
      */
     void AddTimer(const std::weak_ptr<PMLogic::Helper::Timer> &timer);

     void AddStopWatch(const std::weak_ptr<PMLogic::Helper::StopWatch> &stopWatch);
};

#endif // PACMAN_DELTATIME_H
