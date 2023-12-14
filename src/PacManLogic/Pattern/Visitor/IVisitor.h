//

#ifndef PACMAN_IVISITOR_H
#define PACMAN_IVISITOR_H


#include "PMLogic.h"

class PMLogic::IVisitor {
public:
    virtual ~IVisitor() = default;
};

#endif // PACMAN_IVISITOR_H
