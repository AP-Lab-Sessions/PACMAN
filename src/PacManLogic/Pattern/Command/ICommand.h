//

#ifndef PACMAN_ICOMMAND_H
#define PACMAN_ICOMMAND_H

#include "PMLogic.h"
#include "Pattern/Observer/Event/Event.h"

template<typename CommandType>
class PMLogic::ICommand : public Event<CommandType> {
public:
    ~ICommand() override = default;
    virtual void Execute() = 0;
    virtual void ExecuteAndNotify() =0;
};


#endif //PACMAN_ICOMMAND_H
