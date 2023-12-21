//

#include "Fruit.h"

Fruit::Fruit(const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size) :
CollectableEntity(startPosition, size, 25, true) {}

void Fruit::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}

void Fruit::CollideWith(PMLogic::Entity &entity) {
    entity.CollideWith(*this);
}