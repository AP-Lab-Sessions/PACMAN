//

#ifndef PACMAN_ENTITYDESTROYEVENT_H
#define PACMAN_ENTITYDESTROYEVENT_H

#include "Pattern/Observer/Event/Event.h"

/**
 * @brief Called when an entity gets destroyed.
 */
struct EntityDestroyEvent : public PMLogic::Event<EntityDestroyEvent> {
    std::weak_ptr<PMLogic::Entity> entity;
};


#endif //PACMAN_ENTITYDESTROYEVENT_H
