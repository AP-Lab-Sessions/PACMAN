//

#include "Random.h"

PMLogic::Helper::Random::Random() : generator(std::random_device{}()) {}

int PMLogic::Helper::Random::GetRandomInteger(const int& min, const int& max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

float PMLogic::Helper::Random::GetRandomFloat(const float& min, const float& max) {
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(generator);
}
