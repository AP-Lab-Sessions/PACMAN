#include <iostream>
#include <SFML/Graphics.hpp>
#include "PMLogic.h"
#include "EntityFactory/EntityFactory.h"
int main() {
    EntityFactory ef;
    std::unique_ptr<PMLogic::Entity> entity = ef.Create();
    std::cout << "done!";
    return 0;
}
