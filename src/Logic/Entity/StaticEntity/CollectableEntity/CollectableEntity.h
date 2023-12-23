//

#ifndef PACMAN_COLLECTABLEENTITY_H
#define PACMAN_COLLECTABLEENTITY_H

#include "Entity/StaticEntity/StaticEntity.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"

namespace PMGame::Logic {
/**
 * @brief An entity that can be collected by dynamic entity.
 */
class CollectableEntity : public StaticEntity {
protected:
    /**
     * @brief An optional reward upon collection (for pacman)
     */
    int reward;

public:
    std::unique_ptr<EntityCollectedEvent> onEntityCollected;

    ~CollectableEntity() override = default;

    /**
     *
     * @param startPosition The starting position.
     * @param size The size.
     * @param reward The reward.
     * @param isFruit Boolean denoting if the entity is a fruit.
     */
    CollectableEntity(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size,
                      const int& reward, const bool& isFruit = false);

    /**
     * @brief Gets the reward.
     * @return The reward.
     */
    int GetReward() const;
};
} // namespace PMGame::Logic

#endif // PACMAN_COLLECTABLEENTITY_H
