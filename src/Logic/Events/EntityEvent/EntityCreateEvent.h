//

#ifndef PACMAN_ENTITYCREATEEVENT_H
#define PACMAN_ENTITYCREATEEVENT_H

#include "Coordinate/Coordinate.h"
#include "Pattern/Observer/Event/Event.h"

namespace PMGame::Logic {
/**
 * @brief Called when an entity gets created.
 */
struct EntityCreateEvent : public Event<EntityCreateEvent> {
    const Coordinate2D::NormalizedCoordinate position;
    const Coordinate2D::Coordinate size;
    EntityCreateEvent(Coordinate2D::NormalizedCoordinate position, const Coordinate2D::Coordinate& size)
        : position(std::move(position)), size(size) {}
};
} // namespace PMGame::Logic
#endif // PACMAN_ENTITYCREATEEVENT_H
