//

#ifndef PACMAN_AUTOMATICENTITY_H
#define PACMAN_AUTOMATICENTITY_H

#include "Entity/DynamicEntity/DynamicEntity.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"
#include "Pattern/Observer/EventListener/IEventListener.h"
#include "Events/EntityEvent/EntityDestroyEvent.h"


class AutomaticEntity : public DynamicEntity,
                        public PMLogic::IEventListener<EntityPositionChangeEvent>,
                        public PMLogic::IEventListener<EntityDestroyEvent>{
protected:
    std::unique_ptr<Coordinate2D::NormalizedCoordinate> target;
public:
    AutomaticEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                                           const Coordinate2D::Coordinate &size, const float &speed);
    virtual void ChooseDirection() = 0;

    void Update(const EntityPositionChangeEvent &eventData) override = 0;
    void Update(const EntityDestroyEvent &eventData) override;
};

#endif // PACMAN_AUTOMATICENTITY_H
