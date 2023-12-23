//

#ifndef PACMAN_ENTITYPOSITIONCHANGEEVENT_H
#define PACMAN_ENTITYPOSITIONCHANGEEVENT_H

#include "Coordinate/Coordinate.h"
#include "Pattern/Observer/Event/Event.h"

/**
 * @brief Called when an entity changes position.
 */
struct EntityPositionChangeEvent : public PMLogic::Event<EntityPositionChangeEvent> {
    Coordinate2D::NormalizedCoordinate newPosition;
    explicit EntityPositionChangeEvent(Coordinate2D::NormalizedCoordinate newPosition)
        : newPosition(std::move(newPosition)) {}
};

#endif // PACMAN_ENTITYPOSITIONCHANGEEVENT_H
