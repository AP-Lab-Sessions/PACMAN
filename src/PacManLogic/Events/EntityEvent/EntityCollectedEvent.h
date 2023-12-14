//

#ifndef PACMAN_ENTITYCOLLECTEDEVENT_H
#define PACMAN_ENTITYCOLLECTEDEVENT_H

#include "Pattern/Observer/Event/Event.h"

class CollectableEntity;

class EntityCollectedEvent : public PMLogic::Event<EntityCollectedEvent> {
public:
    const CollectableEntity &entity;
    explicit EntityCollectedEvent(const CollectableEntity &entity) : entity(entity) {}
};

#endif //PACMAN_ENTITYCOLLECTEDEVENT_H
