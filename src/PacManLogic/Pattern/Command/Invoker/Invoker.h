//

#ifndef PACMAN_INVOKER_H
#define PACMAN_INVOKER_H

#include "Pattern/Command/ICommand/ICommand.h"
#include <memory>

class Invoker {
protected:
    std::weak_ptr<PMLogic::ICommand> onStart;
    std::weak_ptr<PMLogic::ICommand> onFinish;

public:
    Invoker() = default;
    Invoker(const std::weak_ptr<PMLogic::ICommand> &onStart, const std::weak_ptr<PMLogic::ICommand> &onFinish);

    void SetOnStart(const std::weak_ptr<PMLogic::ICommand> &onStart);
    void SetOnFinish(const std::weak_ptr<PMLogic::ICommand> &onFinish);
};


#endif //PACMAN_INVOKER_H
