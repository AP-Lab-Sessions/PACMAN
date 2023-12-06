//

#include "PacMan.h"

void PacMan::Eat(const CollectableEntity& collectable) {

}
void PacMan::Accept(const std::weak_ptr<PMLogic::IVisitor>& visitor) const {
    visitor.lock()->Visit(*this);
}