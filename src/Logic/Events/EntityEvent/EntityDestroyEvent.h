//

#ifndef PACMAN_ENTITYDESTROYEVENT_H
#define PACMAN_ENTITYDESTROYEVENT_H

#include "Pattern/Observer/Event/Event.h"

namespace PMGame::Logic {
class Entity;
/**
 * @brief Called when an entity gets destroyed.
 */
struct EntityDestroyEvent : public Event<EntityDestroyEvent> {
    std::weak_ptr<Entity> entity;
};
} // namespace PMGame::Logic

#endif // PACMAN_ENTITYDESTROYEVENT_H
