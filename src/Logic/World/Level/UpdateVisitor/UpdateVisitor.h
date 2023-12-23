//

#ifndef PACMAN_UPDATEVISITOR_H
#define PACMAN_UPDATEVISITOR_H

#include "Entity/IEntityVisitor/IEntityVisitor.h"

namespace PMGame::Logic {
/**
 * @brief Visitor that updates concrete entities in Visit (currently only for dynamic entities)
 */
class UpdateVisitor : public IEntityVisitor {
public:
    void Visit(PacMan& pacMan) const override;
    void Visit(Ghost& ghost) const override;
    void Visit(Wall& wall) const override;
    void Visit(Coin& coin) const override;
    void Visit(Fruit& fruit) const override;
};
} // namespace PMGame::Logic
#endif // PACMAN_UPDATEVISITOR_H
