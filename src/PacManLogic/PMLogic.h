//

#ifndef PACMAN_PMLOGIC_H
#define PACMAN_PMLOGIC_H

/**
 * @brief Classes belonging to the logic part of the PacMan project encapsulated in this namespace.
 */
namespace PMLogic {
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

    /**
     * @brief Entities which essentially are derived from generic subject class but with concrete type
     */
    namespace Entity {
            /**
             * @brief Something that can be collected during the game.
             */
            class Collectable;
            /**
             * @brief A collectable type.
             */
            class Fruit;
            /**
             * @brief A collectable type.
             */
            class Coin;

            /**
             * @brief The enemies of Pac-Man.
             */
            class Ghost;
            /**
             * @brief The playable character of the game.
             */
            class PacMan;
            /**
             * @brief A wall that collides with entities.
             */
            class Wall;
    }
}
#endif // PACMAN_PMLOGIC_H
