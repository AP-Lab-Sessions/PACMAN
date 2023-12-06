//

#include "World.h"
PMLogic::World::World(std::unique_ptr<AbstractFactory> &factoryArg)
    : factory(std::move(factoryArg)){

}