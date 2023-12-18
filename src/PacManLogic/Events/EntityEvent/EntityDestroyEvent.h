//

#ifndef PACMAN_ENTITYDESTROYEVENT_H
#define PACMAN_ENTITYDESTROYEVENT_H

#include "Pattern/Observer/Event/Event.h"

struct EntityDestroyEvent : public PMLogic::Event<EntityDestroyEvent> {
public:
    std::weak_ptr<PMLogic::Entity> entity;
};


#endif //PACMAN_ENTITYDESTROYEVENT_H
