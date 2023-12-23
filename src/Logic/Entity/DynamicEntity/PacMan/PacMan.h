//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "Entity/DynamicEntity/DynamicEntity.h"
#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

namespace PMGame::Logic {
/**
 * @brief The PacMan entity.
 */
class PacMan : public DynamicEntity {
public:
    /**
     *
     * @param startPosition The starting position.
     * @param size The size.
     */
    explicit PacMan(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size);

    /**
     * @brief Collects a collectable entity.
     * @param collectable The collectable entity.
     */
    void Eat(const CollectableEntity& collectable);
    /**
     * @brief Calls the visit function of the visitor
     * @param visitor
     */
    void Accept(const std::weak_ptr<IEntityVisitor>& visitor) override;

    /**
     * @brief Handle collision with itself and a fruit
     */
    void CollideWith(Fruit&) final;
    /**
     * @brief Handle collision with itself and a coin
     */
    void CollideWith(Coin&) final;

    /**
     * @brief Handle collision with itself and an entity
     */
    void CollideWith(Entity&) override;
};
} // namespace PMGame::Logic

#endif // PACMAN_PACMAN_H
