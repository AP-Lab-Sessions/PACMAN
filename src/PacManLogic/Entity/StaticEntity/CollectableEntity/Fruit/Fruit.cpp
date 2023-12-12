//

#include "Fruit.h"

Fruit::Fruit(const Coordinate2D::NormalizedCoordinate &startPosition) :
CollectableEntity(startPosition, {-0.95f, -0.95f}, 25) {}

void Fruit::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}