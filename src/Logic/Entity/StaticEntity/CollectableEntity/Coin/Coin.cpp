//

#include "Coin.h"
#include "Entity/IEntityVisitor/IEntityVisitor.h"

PMGame::Logic::Coin::Coin(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size)
    : CollectableEntity(startPosition, size, 5) {}

void PMGame::Logic::Coin::Accept(const std::weak_ptr<IEntityVisitor>& visitor) { visitor.lock()->Visit(*this); }

void PMGame::Logic::Coin::CollideWith(PMGame::Logic::Entity& entity) { entity.CollideWith(*this); }