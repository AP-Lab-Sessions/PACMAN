//

#include "Invoker.h"

Invoker::Invoker(const std::weak_ptr<PMLogic::ICommand> &onStart, const std::weak_ptr<PMLogic::ICommand> &onFinish):
onStart(onStart), onFinish(onFinish) {}

void Invoker::SetOnFinish(const std::weak_ptr<PMLogic::ICommand> &onFinishArg) {
    onFinish = onFinishArg;
}

void Invoker::SetOnStart(const std::weak_ptr<PMLogic::ICommand> &onStartArg) {
    onStart = onStartArg;
}