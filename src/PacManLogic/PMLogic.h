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


    // Command design pattern

    template<typename CommandType>
    class ICommand;

    class Receiver;

    class Invoker;


    class Entity;

    class AbstractFactory;

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
         class StopWatch;

         class Camera;
         }
}
#endif // PACMAN_PMLOGIC_H
