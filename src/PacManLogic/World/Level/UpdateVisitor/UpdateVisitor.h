//

#ifndef PACMAN_UPDATEVISITOR_H
#define PACMAN_UPDATEVISITOR_H

#include "Entity/IEntityVisitor/IEntityVisitor.h"

/**
 * @brief Visitor that updates concrete entities in Visit (currently only for dynamic entities)
 */
class UpdateVisitor : public IEntityVisitor {
public:
    void Visit(PacMan &pacMan) const override;
    void Visit(Ghost &ghost) const override;
    void Visit(Wall &wall) const override;
    void Visit(Coin &coin) const override;
    void Visit(Fruit &fruit) const override;
};


#endif //PACMAN_UPDATEVISITOR_H
