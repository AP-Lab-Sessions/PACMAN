//
#include "Intersection.h"

PMGame::Logic::Intersection::Intersection(const Coordinate2D::NormalizedCoordinate& startPosition,
                                          const Coordinate2D::Coordinate& size,
                                          const std::list<Coordinate2D::DiscreteDirection2D>& directions)
    : StaticEntity(startPosition, size), directions(directions) {}

void PMGame::Logic::Intersection::CollideWith(PMGame::Logic::Entity& entity) { entity.CollideWith(*this); }
void PMGame::Logic::Intersection::Accept(const std::weak_ptr<IEntityVisitor>&) {}

std::list<PMGame::Logic::Coordinate2D::DiscreteDirection2D> PMGame::Logic::Intersection::GetDirections() const {
    return directions;
}
bool PMGame::Logic::Intersection::operator==(const Intersection& other) const {
    return other.GetPosition() == GetPosition() && other.GetSize() == GetSize() &&
           other.GetDirections() == GetDirections();
}

PMGame::Logic::Intersection::Intersection(const Intersection& other)
    : Intersection(other.GetPosition(), other.GetSize(), other.GetDirections()) {}
