//

#ifndef PACMAN_INTERSECTION_H
#define PACMAN_INTERSECTION_H

#include "Entity/StaticEntity/StaticEntity.h"

namespace PMGame::Logic {
/**
 * @brief The intersection entity that helps dynamic entities get through walls
 */
class Intersection : public StaticEntity {
protected:
    /**
     * @brief The viable directions u can go to from the intersection
     */
    const std::list<Coordinate2D::DiscreteDirection2D> directions;

public:
    /**
     *
     * @param startPosition The starting position.
     * @param size The size.
     * @param directions The directions.
     */
    Intersection(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size,
                 const std::list<Coordinate2D::DiscreteDirection2D>& directions);

    /**
     * @brief Handle collision with itself and an entity
     */
    void CollideWith(Entity&) override;

    /**
     * @brief Calls  the visit function of the visitor
     * @param visitor
     */
    void Accept(const std::weak_ptr<IEntityVisitor>& visitor) override;

    /**
     * @brief Gets the viable directions u can go from the intersecton
     * @return The directions.
     */
    std::list<Coordinate2D::DiscreteDirection2D> GetDirections() const;

    bool operator==(const Intersection& other) const;
    Intersection(const Intersection& other);
    ~Intersection() override = default;
};
} // namespace PMGame::Logic
#endif // PACMAN_INTERSECTION_H
