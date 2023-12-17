//

#ifndef PACMAN_ENTITYCOLLECTEDEVENT_H
#define PACMAN_ENTITYCOLLECTEDEVENT_H

#include "Pattern/Observer/Event/Event.h"

struct EntityCollectedEvent : public PMLogic::Event<EntityCollectedEvent> {
    const int reward;
    const bool collectedFruit;

    explicit EntityCollectedEvent(const int &reward, const bool &collectedFruit)
        : reward(reward), collectedFruit(collectedFruit) {}
};

#endif //PACMAN_ENTITYCOLLECTEDEVENT_H
