//
#include "Intersection.h"

Intersection::Intersection(const Coordinate2D::NormalizedCoordinate& startPosition,
                           const Coordinate2D::Coordinate& size,
                           const std::list<Coordinate2D::DiscreteDirection2D>& directions)
    : StaticEntity(startPosition, size), directions(directions) {}

void Intersection::CollideWith(PMLogic::Entity& entity) { entity.CollideWith(*this); }
void Intersection::Accept(const std::weak_ptr<IEntityVisitor>&) {}

std::list<Coordinate2D::DiscreteDirection2D> Intersection::GetDirections() const { return directions; }
bool Intersection::operator==(const Intersection& other) const {
    return other.GetPosition() == GetPosition() && other.GetSize() == GetSize() &&
           other.GetDirections() == GetDirections();
}

Intersection::Intersection(const Intersection& other)
    : Intersection(other.GetPosition(), other.GetSize(), other.GetDirections()) {}
