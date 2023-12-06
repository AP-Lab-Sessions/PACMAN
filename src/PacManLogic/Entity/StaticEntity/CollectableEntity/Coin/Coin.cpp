//

#include "Coin.h"

Coin::Coin() : CollectableEntity(5) {}

void Coin::Accept(const std::weak_ptr<PMLogic::IVisitor>& visitor) const {
    visitor.lock()->Visit(*this);
}