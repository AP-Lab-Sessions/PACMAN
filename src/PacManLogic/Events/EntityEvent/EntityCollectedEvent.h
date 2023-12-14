//

#ifndef PACMAN_ENTITYCOLLECTEDEEVENT_H
#define PACMAN_ENTITYCOLLECTEDEEVENT_H

#include "Pattern/Observer/Event/Event.h"
#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"

class EntityCollectedeEvent : public PMLogic::Event<EntityCollectedeEvent> {
public:
    const CollectableEntity &entity;
    explicit EntityCollectedeEvent(const CollectableEntity &entity) : entity(entity) {}
};

#endif //PACMAN_ENTITYCOLLECTEDEEVENT_H
