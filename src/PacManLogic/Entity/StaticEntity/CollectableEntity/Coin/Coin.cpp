//

#include "Coin.h"

Coin::Coin(const Coordinate2D::NormalizedCoordinate &startPosition) :
CollectableEntity(startPosition,  {-0.99f, -0.99f},  5) {}

void Coin::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}