//

#include "Random.h"

std::shared_ptr<PMLogic::Helper::Random> PMLogic::Helper::Random::instance{nullptr};

PMLogic::Helper::Random::Random() : generator(std::random_device{}()){}

int PMLogic::Helper::Random::GetRandomInteger(const int& min, const int& max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

std::weak_ptr<PMLogic::Helper::Random> PMLogic::Helper::Random::GetInstance() {
    if(instance == nullptr) {
        std::shared_ptr<PMLogic::Helper::Random> createdInstance{new PMLogic::Helper::Random()};
        instance = createdInstance;
    }
    return instance;
}
