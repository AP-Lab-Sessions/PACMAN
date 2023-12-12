//

#include "PacMan.h"

PacMan::PacMan(const Coordinate2D::NormalizedCoordinate &startPosition) :
DynamicEntity(startPosition, {0.15f,0.15f}, 3, 1.0f) {}

void PacMan::Eat(const CollectableEntity& collectable) {

}
void PacMan::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}