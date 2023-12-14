//

#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H

#include "PMLogic.h"
#include "Pattern/Observer/EventObserver/EventObserver.h"
#include <list>
#include <memory>

template<typename CommandType>
class Event {
protected:
    std::list<std::shared_ptr<EventObserver<CommandType>>> observers;
public:
    virtual ~Event() = default;

    virtual void Attach(const std::shared_ptr<EventObserver<CommandType>> &observer) {
        observers.push_back(observer);
    }
    virtual void Detach(const std::shared_ptr<EventObserver<CommandType>> &observer) {
        observers.remove(observer);
    }
    void Notify(const CommandType &command) {
        for(const auto &currentObserver : observers) {
            currentObserver->Update(command);
        }
    }
};


#endif // PACMAN_EVENT_H
