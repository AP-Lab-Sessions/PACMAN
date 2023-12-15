//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Entity/DynamicEntity/AutomaticEntity/AutomaticEntity.h"

#include <unordered_map>

enum GhostMode {Mode_Stasis, Mode_Chase, Mode_Fear};

class Ghost : public AutomaticEntity {
protected:
    GhostMode mode;
    std::unordered_map<DiscreteDirection2D, bool> viableDirections;

    void ResetViableDirections();

    DiscreteDirection2D GetDirectionWithMinimumDistance() const;
    DiscreteDirection2D GetDirectionWithMaximumDistance() const;
public:
    explicit Ghost(const Coordinate2D::NormalizedCoordinate &startPosition);
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    void CollideWith(PacMan &) final;

    void CollideWith(PMLogic::Entity &) override;

    void CollideWith(Wall &) override;

    GhostMode GetMode() const;
    void SetMode(const GhostMode &);

    void ChooseDirection() override;

    void Update(const EntityPositionChangeEvent &eventData) override;
};

#endif // PACMAN_GHOST_H
