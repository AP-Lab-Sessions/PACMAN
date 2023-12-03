//

#ifndef PACMAN_ISUBJECT_H
#define PACMAN_ISUBJECT_H

#include "Observer/IObserver.h"
#include "PMLogic.h"
#include <list>
#include <memory>

class PMLogic::ISubject {
protected:
    std::list<std::weak_ptr<PMLogic::IObserver>> observers;
public:
    virtual ~ISubject() = default;

    virtual void NotifyAll() = 0;
    virtual void Attach(const std::weak_ptr<PMLogic::IObserver> &observer) = 0;
    virtual void Detach(const std::weak_ptr<PMLogic::IObserver> &observer) = 0;
};

#endif // PACMAN_ISUBJECT_H
