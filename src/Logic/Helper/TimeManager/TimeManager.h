//

#ifndef PACMAN_TIMEMANAGER_H
#define PACMAN_TIMEMANAGER_H

#include "Pattern/Singleton/Singleton.h"

#include <chrono>
#include <functional>
#include <list>

namespace PMGame::Logic::Helper {
/**
 * @brief A timer that calls a callback when the specified time has run out.
 */
class Timer {
public:
    /**
     * @brief Function that will be called when the timer ends.
     */
    const std::function<void()> callback;
    /**
     * @brief The duration of the timer.
     */
    float duration;

    /**
     *
     * @param callback The callback function.
     * @param duration Duration of the timer.
     */
    Timer(const std::function<void()>& callback, const float& duration);
};

/**
 * @brief A stopwatch that can be paused, resumed, and tracked. Used by TimeManager for its core function
 */
class StopWatch {
protected:
    /**
     * @brief Boolean denoting if the stopwatch is currently paused.
     */
    bool isPaused;
    /**
     * @brief Time when the stopwatch started
     */
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    /**
     * @brief A time that helps with pausing and resuming
     */
    std::chrono::time_point<std::chrono::steady_clock> capturedTime;

public:
    StopWatch();
    /**
     * @brief Start the stopwatch.
     */
    void Start();

    /**
     * @brief Get the current time of the stopwatch
     * @return The stopwatch time.
     */
    float GetCurrentTime();

    /**
     * @brief Pause the stopwatch.
     */
    void Pause();

    /**
     * @brief Resume the stopwatch.
     */
    void Resume();

    /**
     * @brief Tells if the stopwatch is currently paused.
     * @return Boolean denoting if the stopwatch is currently paused.
     */
    bool GetIsPaused() const;
};

/**
 * @brief Keeps the difference in time between current update step (tick) and the previous one.
 * Furthermore it also manages timers and stopwatches that get updated in accordance to deltatime
 */
class TimeManager : public PMGame::Logic::Singleton<TimeManager> {
protected:
    TimeManager();

    /**
     * @brief The difference in time between current tick and the previous one
     */
    float deltaTime;
    /**
     * @brief Stopwatch used to calculate deltatime
     */
    std::unique_ptr<StopWatch> stopWatch;

    /**
     * @brief Timers that get updated in accordance to deltatime
     */
    std::list<std::weak_ptr<Timer>> timers;
    /**
     * @brief Stopwatches that get updated in accordance to deltatime
     */
    std::list<std::weak_ptr<StopWatch>> stopWatches;

public:
    /**
     * @brief Pauses all stopwatches
     */
    void Pause();

    /**
     * @brief Updates deltatime by getting to the next update step
     */
    void Tick();

    /**
     * @brief Gets deltaTime
     * @return deltaTime
     */
    float GetDeltaTime() const;

    /**
     * @brief Adds a timer
     * @param callBack
     * @param duration
     */
    void AddTimer(const std::weak_ptr<Timer>& timer);

    /**
     * @brief Adds a stopwatch
     * @param stopWatch
     */
    void AddStopWatch(const std::weak_ptr<StopWatch>& stopWatch);
};
} // namespace PMGame::Logic::Helper

#endif // PACMAN_TIMEMANAGER_H