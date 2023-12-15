//

#ifndef PACMAN_UPDATEVISITOR_H
#define PACMAN_UPDATEVISITOR_H

#include "Entity/IEntityVisitor/IEntityVisitor.h"
#include "Entity/Entity.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include <memory>

class UpdateVisitor : public IEntityVisitor {
public:

    void Visit(PacMan &pacMan) const override;
    void Visit(Ghost &ghost) const override;
    void Visit(Wall &wall) const override;
    void Visit(Coin &coin) const override;
    void Visit(Fruit &fruit) const override;
};


#endif //PACMAN_UPDATEVISITOR_H
