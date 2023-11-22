//

#ifndef PACMAN_PMLOGIC_H
#define PACMAN_PMLOGIC_H

/**
 * @brief Classes belonging to the logic part of the PacMan project encapsulated in this namespace.
 */
namespace PMLogic {
    /**
          * @brief Entity.
     */
    class Entity;
    /**
     * @brief Subject and Observer design for the generic observer pattern
     * @tparam Type Generic type
     */
    template<typename Type> class Subject;
    template<typename Type> class Observer;

    /**
     * @brief Interface abstract factory that creates entities of generic type
     * @tparam EntityType Generic type of entity
     */
    template<typename EntityType> class AbstractFactory;

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
     }
}
#endif // PACMAN_PMLOGIC_H
