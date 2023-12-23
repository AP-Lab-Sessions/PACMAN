//

#include "Randomizer.h"

PMGame::Logic::Helper::Randomizer::Randomizer() : generator(std::random_device{}()) {}

int PMGame::Logic::Helper::Randomizer::GetRandomInteger(const int& min, const int& max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

float PMGame::Logic::Helper::Randomizer::GetRandomFloat(const float& min, const float& max) {
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(generator);
}
