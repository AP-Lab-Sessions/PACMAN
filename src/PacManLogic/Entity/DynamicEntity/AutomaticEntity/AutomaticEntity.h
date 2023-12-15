//

#ifndef PACMAN_AUTOMATICENTITY_H
#define PACMAN_AUTOMATICENTITY_H

#include "Entity/DynamicEntity/DynamicEntity.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"
#include "Pattern/Observer/EventListener/IEventListener.h"


class AutomaticEntity : public DynamicEntity, public PMLogic::IEventListener<EntityPositionChangeEvent> {
protected:
    std::unique_ptr<Coordinate2D::NormalizedCoordinate> target;
public:
    AutomaticEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                                           const Coordinate2D::Coordinate &size,
                                           const unsigned int &lives, const float &speed);
    virtual void ChooseDirection() = 0;
};

#endif // PACMAN_AUTOMATICENTITY_H
