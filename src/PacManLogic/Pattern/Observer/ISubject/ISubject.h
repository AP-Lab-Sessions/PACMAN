//

#ifndef PACMAN_ISUBJECT_H
#define PACMAN_ISUBJECT_H

#include "PMLogic.h"
#include "Pattern/Observer/IObserver/IObserver.h"
#include <list>
#include <memory>


class PMLogic::ISubject {
protected:
    std::list<std::weak_ptr<PMLogic::IObserver>> observers;
public:
    virtual ~ISubject() = default;

    virtual void NotifyAll() = 0;
    virtual void Attach(const std::weak_ptr<PMLogic::IObserver> &observer);
    virtual void Detach(const std::weak_ptr<PMLogic::IObserver> &observer);
};

#endif // PACMAN_ISUBJECT_H
