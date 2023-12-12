//

#include "Ghost.h"

Ghost::Ghost(const Coordinate2D::NormalizedCoordinate &startPosition) :
DynamicEntity(startPosition, {0.05f,0.05f}, 1, 0.9f) {}

void Ghost::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}