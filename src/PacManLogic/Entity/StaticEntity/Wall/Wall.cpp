//

#include "Wall.h"

Wall::Wall() : StaticEntity(false, true) {}

void Wall::Accept(const std::weak_ptr<PMLogic::IVisitor>& visitor) const {
    visitor.lock()->Visit(*this);
}