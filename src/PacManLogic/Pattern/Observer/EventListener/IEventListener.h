//

#ifndef PACMAN_IEVENTLISTENER_H
#define PACMAN_IEVENTLISTENER_H

#include "PMLogic.h"

/**
     * @brief A listener/observer that listens/observes to EventType
     * @tparam EventType
 */
template<typename EventType>
class PMLogic::IEventListener {
public:
    /**
     * @brief Called when event EventType happened.
     * @param eventData Event-specific information
     */
    virtual void Update(const EventType &eventData) = 0;
    virtual ~IEventListener() = default;
};

#endif // PACMAN_IEVENTLISTENER_H
