//

#include "Ghost.h"

void Ghost::Accept(const std::weak_ptr<PMLogic::IVisitor>& visitor) const {
    visitor.lock()->Visit(*this);
}