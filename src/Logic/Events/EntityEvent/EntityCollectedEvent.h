//

#ifndef PACMAN_ENTITYCOLLECTEDEVENT_H
#define PACMAN_ENTITYCOLLECTEDEVENT_H

#include "Pattern/Observer/Event/Event.h"

namespace PMGame::Logic {
/**
 * @brief Called when a collectable entity gets collected or when a ghost gets eaten.
 */
struct EntityCollectedEvent : public Event<EntityCollectedEvent> {
    const int reward;
    const bool collectedFruit;

    explicit EntityCollectedEvent(const int& reward, const bool& collectedFruit)
        : reward(reward), collectedFruit(collectedFruit) {}
};
} // namespace PMGame::Logic

#endif // PACMAN_ENTITYCOLLECTEDEVENT_H
