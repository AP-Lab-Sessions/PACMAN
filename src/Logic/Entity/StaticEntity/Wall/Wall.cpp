//

#include "Wall.h"
#include "Entity/IEntityVisitor/IEntityVisitor.h"

PMGame::Logic::Wall::Wall(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size)
    : StaticEntity(startPosition, size) {}

void PMGame::Logic::Wall::Accept(const std::weak_ptr<IEntityVisitor>& visitor) { visitor.lock()->Visit(*this); }

void PMGame::Logic::Wall::CollideWith(PMGame::Logic::Entity& entity) { entity.CollideWith(*this); }