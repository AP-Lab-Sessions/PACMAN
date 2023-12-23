//

#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H

#include "PMLogic.h"
#include "Pattern/Observer/EventListener/IEventListener.h"
#include <list>
#include <memory>
#include <iostream>

/**
     * @brief An event that can attach eventlisteners to itself
     * @tparam EventType the type of the event
 */
template<typename EventType>
class PMLogic::Event {
protected:
    /**
     * @brief The observers of the event.
     */
    std::list<std::weak_ptr<PMLogic::IEventListener<EventType>>> observers;
public:
    Event() : observers({}) {}

    virtual ~Event() = default;

    /**
     * @brief Attaches an event listener to the event.
     * @param observer
     */
    virtual void Attach(const std::shared_ptr<PMLogic::IEventListener<EventType>> &observer) {
        observers.push_back(observer);
    }
    /**
     * @brief Detaches an event listener to the event.
     * @param observer
     */
    virtual void Detach(const std::shared_ptr<PMLogic::IEventListener<EventType>> &observer) {
        for(auto iter=observers.begin();iter!=observers.end();iter++) {
            if(iter->expired() || iter->lock() == observer) iter = observers.erase(iter);
        }
    }
    /**
     * @brief Notifies all event listeners that the event happened.
     * @param eventData
     */
    virtual void Notify(const EventType &eventData) {
        for(auto iter=observers.begin();iter!=observers.end();iter++) {
            if(iter->expired()) iter = observers.erase(iter);
            else iter->lock()->Update(eventData);
        }
    }
};


#endif // PACMAN_EVENT_H
