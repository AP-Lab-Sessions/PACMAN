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

    void CleanUp() {
        for(auto iter=observers.begin();iter!=observers.end();iter++) {
            if(iter->expired()) iter = observers.erase(iter);
        }
    }
public:
    virtual ~Event() = default;

    virtual void Attach(const std::shared_ptr<PMLogic::IEventListener<EventType>> &observer) {
        observers.push_back(observer);
    }
    virtual void Detach(const std::shared_ptr<PMLogic::IEventListener<EventType>> &observer) {
        CleanUp();
        for(auto iter=observers.begin();iter!=observers.end();iter++) {
            if(iter->lock() == observer) iter = observers.erase(iter);
        }
    }
    virtual void Notify(const EventType &command) {
        CleanUp();
        for(auto iter=observers.begin();iter!=observers.end();iter++) {
            iter->lock()->Update(command);
        }
    }
};


#endif // PACMAN_EVENT_H
