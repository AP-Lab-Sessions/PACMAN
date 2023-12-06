//

#ifndef WORLD_H
#define WORLD_H

#include "PMLogic.h"
#include "AbstractFactory/AbstractFactory.h"
#include <memory>

class PMLogic::World {
protected:
    const std::unique_ptr<AbstractFactory> factory;
public:
    explicit World(std::unique_ptr<AbstractFactory> &factory);
};

#endif
