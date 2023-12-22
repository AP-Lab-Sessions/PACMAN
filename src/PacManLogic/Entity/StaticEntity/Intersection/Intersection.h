//

#ifndef PACMAN_INTERSECTION_H
#define PACMAN_INTERSECTION_H

#include "Entity/StaticEntity/StaticEntity.h"

class Intersection : public StaticEntity {
protected:
    const std::list<Coordinate2D::DiscreteDirection2D> directions;
public:
    Intersection(const Coordinate2D::NormalizedCoordinate &startPosition,
                 const Coordinate2D::Coordinate &size,
                 const std::list<Coordinate2D::DiscreteDirection2D> &directions);
    void CollideWith(PMLogic::Entity &) override;
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    std::list<Coordinate2D::DiscreteDirection2D> GetDirections() const;

    bool operator==(const Intersection &other) const;
    Intersection(const Intersection &other);
    ~Intersection() override = default;
};

#endif // PACMAN_INTERSECTION_H
