//

#include "UpdateVisitor.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/Ghost/Ghost.h"
#include <iostream>



void UpdateVisitor::Visit(Coin &coin) const {

}

void UpdateVisitor::Visit(Wall &wall) const {

}

void UpdateVisitor::Visit(Fruit &fruit) const {

}

void UpdateVisitor::Visit(Ghost &ghost) const {
    ghost.Move();
}

void UpdateVisitor::Visit(PacMan &pacMan) const {
    pacMan.Move();
}