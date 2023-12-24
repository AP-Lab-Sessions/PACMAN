//

#include "Fruit.h"
#include "Entity/IEntityVisitor/IEntityVisitor.h"

PMGame::Logic::Fruit::Fruit(const Coordinate2D::NormalizedCoordinate& startPosition,
                            const Coordinate2D::Coordinate& size)
    : CollectableEntity(startPosition, size, 25, true) {}

void PMGame::Logic::Fruit::Accept(const std::weak_ptr<IEntityVisitor>& visitor) { visitor.lock()->Visit(*this); }

void PMGame::Logic::Fruit::CollideWith(PMGame::Logic::Entity& entity) const { entity.CollideWith(*this); }