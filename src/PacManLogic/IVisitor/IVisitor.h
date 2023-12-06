//

#ifndef PACMAN_IVISITOR_H
#define PACMAN_IVISITOR_H


#include "PMLogic.h"

class PacMan;
class Ghost;
class Wall;
class Coin;
class Fruit;

class PMLogic::IVisitor {
public:
    virtual ~IVisitor() = default;
    virtual void Visit(const PacMan &pacMan) const = 0;
    virtual void Visit(const Ghost &ghost) const = 0;
    virtual void Visit(const Wall &wall) const = 0;
    virtual void Visit(const Coin &coin) const = 0;
    virtual void Visit(const Fruit &fruit) const = 0;
};

#endif // PACMAN_IVISITOR_H
