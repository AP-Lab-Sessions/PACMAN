//

#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H

#include "Entity/StaticEntity/StaticEntity.h"

/**
 * @brief The wall entity that blocks dynamic entities from further moving past the wall.
 */
class Wall : public StaticEntity {
public:
    /**
     *
     * @param startPosition The starting position.
     * @param size The size.
     */
    Wall(const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size);

    /**
     * @brief Calls the visit function of the visitor
     * @param visitor
     */
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    /**
     * @brief Handle collision with itself and an entity.
     */
    void CollideWith(PMLogic::Entity &) override;
};

#endif // PACMAN_WALL_H
