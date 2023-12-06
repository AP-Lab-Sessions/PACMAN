//

#include "Fruit.h"

Fruit::Fruit() : CollectableEntity(25) {}

void Fruit::Accept(const std::weak_ptr<PMLogic::IVisitor>& visitor) const {
    visitor.lock()->Visit(*this);
}