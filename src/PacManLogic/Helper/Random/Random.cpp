//

#include "Random.h"

std::shared_ptr<Helper::Random> Helper::Random::instance{nullptr};

Helper::Random::Random() : generator(std::random_device{}()){}

int Helper::Random::GetRandomInteger(const int& min, const int& max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

std::shared_ptr<Helper::Random> Helper::Random::GetInstance() {
    if(instance == nullptr) {
        std::shared_ptr<Helper::Random> instance1{new Helper::Random()};
        instance = instance1;
    }
    return instance;
}
