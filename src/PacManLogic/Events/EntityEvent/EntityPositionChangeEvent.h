//

#ifndef PACMAN_ENTITYPOSITIONCHANGEEVENT_H
#define PACMAN_ENTITYPOSITIONCHANGEEVENT_H

#include "Pattern/Observer/Event/Event.h"
#include "Coordinate/Coordinate.h"

class EntityPositionChangeEvent : public PMLogic::Event<EntityPositionChangeEvent> {
public:
    Coordinate2D::NormalizedCoordinate newPosition;
    explicit EntityPositionChangeEvent(Coordinate2D::NormalizedCoordinate newPosition)
    : newPosition(std::move(newPosition)) {}
};


#endif //PACMAN_ENTITYPOSITIONCHANGEEVENT_H
