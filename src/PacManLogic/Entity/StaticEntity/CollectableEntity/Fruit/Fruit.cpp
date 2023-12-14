//

#include "Fruit.h"

Fruit::Fruit(const Coordinate2D::NormalizedCoordinate &startPosition) :
CollectableEntity(startPosition, {0.1, 0.1f}, 25) {}

void Fruit::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}

void Fruit::CollideWith(PacMan &) {}

void Fruit::CollideWith(PMLogic::Entity &entity) {
    entity.CollideWith(*this);
}