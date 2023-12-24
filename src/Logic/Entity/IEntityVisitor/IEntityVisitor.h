//

#ifndef PACMAN_IENTITYVISITOR_H
#define PACMAN_IENTITYVISITOR_H

#include "Pattern/Visitor/IVisitor.h"

namespace PMGame::Logic {
// forward declarations
class PacMan;
class Ghost;
class Wall;
class Coin;
class Fruit;

/**
 * @brief An abstract visitor that visits all concrete entities
 */
class IEntityVisitor : public IVisitor {
public:
    ~IEntityVisitor() override = default;

    virtual void Visit(PacMan& pacMan) const = 0;
    virtual void Visit(Ghost& ghost) const = 0;
    virtual void Visit(Wall& wall) const = 0;
    virtual void Visit(Coin& coin) const = 0;
    virtual void Visit(Fruit& fruit) const = 0;
};
} // namespace PMGame::Logic

#endif // PACMAN_IENTITYVISITOR_H