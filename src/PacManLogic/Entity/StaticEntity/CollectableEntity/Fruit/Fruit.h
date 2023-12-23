//

#ifndef PACMAN_FRUIT_H
#define PACMAN_FRUIT_H

#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

/**
 * @brief A concrete collectable entity.
 */
class Fruit : public CollectableEntity {
public:
    /**
     *
     * @param startPosition The starting position.
     * @param size The size.
     */
    explicit Fruit(const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size);

    /**
     * @brief Calls  the visit function of the visitor
     * @param visitor
     */
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    /**
     * @brief Handle collision with itself and an entity
     */
    void CollideWith(PMLogic::Entity &) override;
};

#endif // PACMAN_FRUIT_H
