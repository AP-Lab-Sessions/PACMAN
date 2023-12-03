//

#ifndef PACMAN_VISITOR_H
#define PACMAN_VISITOR_H

#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/Wall/Wall.h"

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void Visit(const PMLogic::Entity &entity) const = 0;
    virtual void Visit(const PacMan &pacMan) const = 0;
    virtual void Visit(const Ghost &ghost) const = 0;
    virtual void Visit(const Wall &wall) const = 0;
    virtual void Visit(const Coin &coin) const = 0;
    virtual void Visit(const Fruit &fruit) const = 0;
};

#endif // PACMAN_VISITOR_H
