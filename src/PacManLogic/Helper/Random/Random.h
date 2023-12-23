//

#ifndef PACMAN_RANDOM_H
#define PACMAN_RANDOM_H

#include "PMLogic.h"
#include "Pattern/Singleton/Singleton.h"
#include <random>



/**
 * @brief A Singleton helper class that generates a random number (float or integer) between x and y
 */
class PMLogic::Helper::Random : public PMLogic::Singleton<PMLogic::Helper::Random> {
protected:
    std::mt19937 generator;
    Random();
public:
    /**
     * @brief Generates a pseudo-random integer between min and max
     * @param min
     * @param max
     * @return the generated random integer
     */
    int GetRandomInteger(const int &min=1, const int &max=100);

    /**
     * @briwf Gets a random float between min and max
     * @param min
     * @param max
     * @return The random float.
     */
    float GetRandomFloat(const float &min=0.0f, const float &max=1.0f);
};


#endif // PACMAN_RANDOM_H
