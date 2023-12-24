//

#ifndef PACMAN_ENTITYDIRECTIONCHANGEEVENT_H
#define PACMAN_ENTITYDIRECTIONCHANGEEVENT_H

#include "Coordinate/Coordinate.h"
#include "Pattern/Observer/Event/Event.h"

namespace PMGame::Logic {
/**
 * @brief Called when a dynamic entity changes direction.
 */
struct EntityDirectionChangeEvent : public Event<EntityDirectionChangeEvent> {
    Coordinate2D::DiscreteDirection2D newDirection;

    explicit EntityDirectionChangeEvent(const Coordinate2D::DiscreteDirection2D& newDirection)
        : newDirection(newDirection) {}
};
} // namespace PMGame::Logic

#endif // PACMAN_ENTITYDIRECTIONCHANGEEVENT_H