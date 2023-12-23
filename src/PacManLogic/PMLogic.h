//

#ifndef PACMAN_PMLOGIC_H
#define PACMAN_PMLOGIC_H

/**
 * @brief Core classes belonging to the logic part of the PacMan project encapsulated in this namespace.
 */
namespace PMLogic {

// Observer design pattern

template <typename EventType>
class IEventListener;

template <typename EventType>
class Event;

// Visitor design pattern

class IVisitor;

class Entity;

class AbstractFactory;

template <typename Type>
class Singleton;

class World;

class Score;

class Scoreboard;

/**
 * @brief Utility classes
 */
namespace Helper {

class Random;

class TimeManager;

class Timer;

class StopWatch;

class Camera;
} // namespace Helper
} // namespace PMLogic
#endif // PACMAN_PMLOGIC_H
