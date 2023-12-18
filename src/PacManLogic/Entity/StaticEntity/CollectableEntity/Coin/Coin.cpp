//

#include "Coin.h"

Coin::Coin(const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size) :
CollectableEntity(startPosition,  size,  5) {}

void Coin::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}

void Coin::CollideWith(PacMan &) {}

void Coin::CollideWith(PMLogic::Entity &entity) {
    entity.CollideWith(*this);
}