//

#ifndef PACMAN_ENTITYCOLLECTEDEVENT_H
#define PACMAN_ENTITYCOLLECTEDEVENT_H

#include "Pattern/Observer/Event/Event.h"

class CollectableEntity;

class EntityCollectedEvent : public PMLogic::Event<EntityCollectedEvent> {
public:
    const int reward;
    const bool collectedFruit;

    explicit EntityCollectedEvent(const int &reward, const bool &collectedFruit);
};

#endif //PACMAN_ENTITYCOLLECTEDEVENT_H
