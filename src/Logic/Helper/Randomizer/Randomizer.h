//

#ifndef PACMAN_RANDOMIZER_H
#define PACMAN_RANDOMIZER_H

#include "Pattern/Singleton/Singleton.h"
#include <random>

namespace PMGame::Logic::Helper {
/**
 * @brief A Singleton helper class that generates a random number (float or integer) between x and y
 */
class Randomizer : public Singleton<Randomizer> {
protected:
    std::mt19937 generator;
    Randomizer();

public:
    /**
     * @brief Generates a pseudo-random integer between min and max
     * @param min
     * @param max
     * @return the generated random integer
     */
    int GetRandomInteger(const int& min = 1, const int& max = 100);

    /**
     * @briwf Gets a random float between min and max
     * @param min
     * @param max
     * @return The random float.
     */
    float GetRandomFloat(const float& min = 0.0f, const float& max = 1.0f);
};
} // namespace PMGame::Logic::Helper

#endif // PACMAN_RANDOMIZER_H
