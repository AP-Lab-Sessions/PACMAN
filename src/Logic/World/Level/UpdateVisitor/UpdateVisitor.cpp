//

#include "UpdateVisitor.h"

#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/Wall/Wall.h"

void PMGame::Logic::UpdateVisitor::Visit(Coin&) const {}

void PMGame::Logic::UpdateVisitor::Visit(Wall&) const {}

void PMGame::Logic::UpdateVisitor::Visit(Fruit&) const {}

void PMGame::Logic::UpdateVisitor::Visit(Ghost& ghost) const {
    if (ghost.GetMode() != Mode_Stasis)
        ghost.Move();
}

void PMGame::Logic::UpdateVisitor::Visit(PacMan& pacMan) const { pacMan.Move(); }