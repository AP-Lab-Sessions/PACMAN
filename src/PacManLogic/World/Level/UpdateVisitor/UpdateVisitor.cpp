//

#include "UpdateVisitor.h"

#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/Wall/Wall.h"

void UpdateVisitor::Visit(Coin &) const {}

void UpdateVisitor::Visit(Wall &) const {}

void UpdateVisitor::Visit(Fruit &) const {}

void UpdateVisitor::Visit(Ghost &ghost) const {
    if(ghost.GetMode() != Mode_Stasis) ghost.Move();
}

void UpdateVisitor::Visit(PacMan &pacMan) const {
    pacMan.Move();
}