//

#ifndef PACMAN_IOBSERVER_H
#define PACMAN_IOBSERVER_H

#include "PMLogic.h"

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void Update() = 0;
};

#endif // PACMAN_IOBSERVER_H
