//

#ifndef PACMAN_IEVENTLISTENER_H
#define PACMAN_IEVENTLISTENER_H

#include "PMLogic.h"

template<typename EventType>
class PMLogic::IEventListener {
public:
    virtual void Update(const EventType &eventData) = 0;
    virtual ~IEventListener() = default;
};

#endif // PACMAN_IEVENTLISTENER_H
