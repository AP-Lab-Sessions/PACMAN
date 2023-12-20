//

#ifndef PACMAN_PMLOGIC_H
#define PACMAN_PMLOGIC_H

/**
 * @brief Classes belonging to the logic part of the PacMan project encapsulated in this namespace.
 */
namespace PMLogic {

    // Observer design pattern

    template<typename CommandType>
    class IEventListener;

    template<typename CommandType>
    class Event;


    // Visitor design pattern

    class IVisitor;

    class Entity;

    class AbstractFactory;

    template<typename Type>
    class Singleton;

    /**
     * @brief The world class
     */
    class World;

    /**
     * @brief An observer of Pac-Man, adds or decreases score based on actions of Pac-Man/player.
     */
    class Score;

    /**
     * @brief A singleton which loads and writes to a file keeping top 5 high scores of all time.
     */
    class Scoreboard;

    /**
     * @brief The singleton helper classes
     */
     namespace Helper {
         /**
          * @brief Random number generator.
          */
         class Random;
         /**
          * @brief Keeps the difference in time between current update step and the previous one.
          */
         class DeltaTime;

         class Timer;

         class StopWatch;

         /**
          * @brief
          */
         class Camera;
         }
}
#endif // PACMAN_PMLOGIC_H
