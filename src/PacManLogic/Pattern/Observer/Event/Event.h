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
    std::list<std::shared_ptr<PMLogic::IEventListener<EventType>>> observers;
public:
    virtual ~Event() = default;

    virtual void Attach(const std::shared_ptr<PMLogic::IEventListener<EventType>> &observer) {
        observers.push_back(observer);
    }
    virtual void Detach(const std::shared_ptr<PMLogic::IEventListener<EventType>> &observer) {
        observers.remove(observer);
    }
    virtual void Notify(const EventType &command) {
        for(const auto &currentObserver : observers) {
            currentObserver->Update(command);
        }
    }
};


#endif // PACMAN_EVENT_H
