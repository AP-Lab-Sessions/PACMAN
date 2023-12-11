//

#ifndef PACMAN_ICOMMAND_H
#define PACMAN_ICOMMAND_H

#include "PMLogic.h"

class PMLogic::ICommand {
public:
    virtual ~ICommand() = default;

    virtual void Execute() const = 0;
};


#endif //PACMAN_ICOMMAND_H
