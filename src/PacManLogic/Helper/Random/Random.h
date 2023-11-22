//

#ifndef PACMAN_RANDOM_H
#define PACMAN_RANDOM_H

#include "PMLogic.h"
#include <random>
#include <memory>



/**
 * @brief A Singleton helper class that generates a random integer between x and y
 */
class PMLogic::Helper::Random {
private:
    std::mt19937 generator;
    Random();
    static std::shared_ptr<PMLogic::Helper::Random> instance;
public:
    /**
     * @brief Make the assignment operator deleted
     */
    void operator=(const PMLogic::Helper::Random &) = delete;
    /**
     * @brief Make the copy constructor deleted
     */
    Random(PMLogic::Helper::Random &) = delete;

    /**
     * @brief Gets the single instance of the class
     * @return The pointer to the instance
     */
    static std::shared_ptr<PMLogic::Helper::Random> GetInstance();
    /**
     * @brief Generates a pseudo-random integer between min and max
     * @param min
     * @param max
     * @return the generated random integer
     */
    int GetRandomInteger(const int &min=1, const int &max=100);
};


#endif // PACMAN_RANDOM_H
