#include <iostream>
#include <SFML/Graphics.hpp>
#include "EntityFactory/EntityFactory.h"
#include "Entity/PacMan/PacMan.h"
int main() {
    EntityFactory<PacMan> pacManFactory;
    std::unique_ptr<PMLogic::Entity> entity = pacManFactory.Create();
    return 0;
}
