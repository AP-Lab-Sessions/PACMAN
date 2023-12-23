//

#include "Wall.h"
#include "Entity/IEntityVisitor/IEntityVisitor.h"

Wall::Wall(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size)
    : StaticEntity(startPosition, size) {}

void Wall::Accept(const std::weak_ptr<IEntityVisitor>& visitor) { visitor.lock()->Visit(*this); }

void Wall::CollideWith(PMLogic::Entity& entity) { entity.CollideWith(*this); }
