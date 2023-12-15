//

#include "UpdateVisitor.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"

void UpdateVisitor::Visit(Coin &coin) const {}

void UpdateVisitor::Visit(Wall &wall) const {}

void UpdateVisitor::Visit(Fruit &fruit) const {}

void UpdateVisitor::Visit(Ghost &ghost) const {
    ghost.Move();
    ghost.SetCanMove(true);
    ghost.ResetViableDirections();
}

void UpdateVisitor::Visit(PacMan &pacMan) const {
    pacMan.Move();
    pacMan.SetCanMove(true);
}