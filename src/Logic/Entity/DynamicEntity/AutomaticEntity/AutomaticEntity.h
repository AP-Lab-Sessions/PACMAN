//

#ifndef PACMAN_AUTOMATICENTITY_H
#define PACMAN_AUTOMATICENTITY_H

#include "Entity/DynamicEntity/DynamicEntity.h"
#include "Events/EntityEvent/EntityDestroyEvent.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"
#include "Pattern/Observer/EventListener/IEventListener.h"

namespace PMGame::Logic {
/**
 * @brief A dynamic entity that has a target it needs to automatically follow.
 */
class AutomaticEntity : public DynamicEntity,
                        public IEventListener<EntityPositionChangeEvent>,
                        public IEventListener<EntityDestroyEvent> {
protected:
    /**
     * @brief The target to follow.
     */
    std::unique_ptr<Coordinate2D::NormalizedCoordinate> target;

public:
    /**
     *
     * @param startPosition The start position.
     * @param size The size.
     * @param speed The default speed.
     */
    AutomaticEntity(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size,
                    const float& speed);

    /**
     * @brief Chooses next direction using the position of the target.
     */
    virtual void ChooseNextDirection() = 0;

    /**
     * @brief Called when the target changes position.
     * @param eventData Information about the target's position
     */
    void Update(const EntityPositionChangeEvent& eventData) override = 0;
    /**
     * @brief Called when the target gets destroyed.
     * @param eventData
     */
    void Update(const EntityDestroyEvent& eventData) override;
};
} // namespace PMGame::Logic
#endif // PACMAN_AUTOMATICENTITY_H
