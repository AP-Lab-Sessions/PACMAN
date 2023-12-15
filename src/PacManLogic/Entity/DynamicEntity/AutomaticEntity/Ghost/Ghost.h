//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Entity/DynamicEntity/DynamicEntity.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"
#include "Pattern/Observer/EventListener/IEventListener.h"

#include <unordered_map>

enum GhostMode {Mode_Stasis, Mode_Chase, Mode_Fear};

class Ghost : public DynamicEntity, public PMLogic::IEventListener<EntityPositionChangeEvent> {
protected:
    GhostMode mode;
    std::unordered_map<DiscreteDirection2D, bool> viableDirections;

    std::unique_ptr<Coordinate2D::NormalizedCoordinate> target;

    void ResetViableDirections();

    DiscreteDirection2D GetDirectionWithMinimumDistance() const;
    DiscreteDirection2D GetDirectionWithMaximumDistance() const;
public:
    explicit Ghost(const Coordinate2D::NormalizedCoordinate &startPosition);
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    void CollideWith(PacMan &) final;

    void CollideWith(PMLogic::Entity &) override;

    void CollideWith(Wall &) override;

    void ChooseDirection();

    GhostMode GetMode() const;
    void SetMode(const GhostMode &);

    void Update(const EntityPositionChangeEvent &eventData) override;
};

#endif // PACMAN_GHOST_H
