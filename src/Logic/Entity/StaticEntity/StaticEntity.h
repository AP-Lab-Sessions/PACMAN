//

#ifndef PACMAN_STATICENTITY_H
#define PACMAN_STATICENTITY_H

#include "Entity/Entity.h"

namespace PMGame::Logic {
/**
 * @brief A collidable entity that never changes positions.
 */
class StaticEntity : public Entity {
public:
    ~StaticEntity() override = default;
    /**
     *
     * @param startPosition The starting position.
     * @param size The size.
     */
    StaticEntity(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size);

    /**
     * @brief Tells if the entity will collide with another
     * @param entity
     * @return Boolean denoting if the entity will collide with another.
     */
    bool WillCollide(const PMGame::Logic::Entity& entity) const override;
};
} // namespace PMGame::Logic
#endif // PACMAN_STATICENTITY_H
