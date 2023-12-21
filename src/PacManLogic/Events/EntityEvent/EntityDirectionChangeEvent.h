//

#ifndef PACMAN_ENTITYDIRECTIONCHANGEEVENT_H
#define PACMAN_ENTITYDIRECTIONCHANGEEVENT_H

#include "Pattern/Observer/Event/Event.h"
#include "Coordinate/Coordinate.h"

struct EntityDirectionChangeEvent : public PMLogic::Event<EntityDirectionChangeEvent> {
    Coordinate2D::DiscreteDirection2D newDirection;

    explicit EntityDirectionChangeEvent(const Coordinate2D::DiscreteDirection2D &newDirection) : newDirection(newDirection) {}
};

#endif // PACMAN_ENTITYDIRECTIONCHANGEEVENT_H
