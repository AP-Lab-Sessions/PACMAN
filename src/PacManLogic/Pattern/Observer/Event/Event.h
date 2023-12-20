//

#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H

#include "PMLogic.h"
#include "Pattern/Observer/EventListener/IEventListener.h"
#include <list>
#include <memory>
#include <iostream>

template<typename EventType>
class PMLogic::Event {
protected:
    std::list<std::weak_ptr<PMLogic::IEventListener<EventType>>> observers;
public:
    virtual ~Event() = default;

    virtual void Attach(const std::shared_ptr<PMLogic::IEventListener<EventType>> &observer) {
        observers.push_back(observer);
    }
    virtual void Detach(const std::shared_ptr<PMLogic::IEventListener<EventType>> &observer) {
        for(auto iter=observers.begin();iter!=observers.end();iter++) {
            if(iter->expired() || iter->lock() == observer) iter = observers.erase(iter);
        }
    }
    virtual void Notify(const EventType &eventData) {
        for(auto iter=observers.begin();iter!=observers.end();iter++) {
            if(iter->expired()) iter = observers.erase(iter);
            else iter->lock()->Update(eventData);
        }
    }
};


#endif // PACMAN_EVENT_H
