//

#ifndef PACMAN_IEVENTLISTENER_H
#define PACMAN_IEVENTLISTENER_H

#include "PMLogic.h"

template<typename CommandType>
class PMLogic::IEventListener {
public:
    virtual void Update(const CommandType &eventData) = 0;
    virtual ~IEventListener() = default;
};

#endif // PACMAN_IEVENTLISTENER_H
