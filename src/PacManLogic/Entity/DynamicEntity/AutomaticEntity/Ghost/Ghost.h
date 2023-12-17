//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Entity/DynamicEntity/AutomaticEntity/AutomaticEntity.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"
#include "Events/GhostEvent/GhostModeChangeEvent.h"

#include <unordered_map>

enum GhostMode : short {Mode_Stasis, Mode_Chase, Mode_Fear};

class Ghost : public AutomaticEntity,
              public PMLogic::IEventListener<EntityCollectedEvent>
{
private:
    std::shared_ptr<PMLogic::Helper::Timer> modeTimer;
protected:
    GhostMode mode;
    std::list<DiscreteDirection2D> viableDirections;

    DiscreteDirection2D GetDirectionWithMinimumDistance() const;
    DiscreteDirection2D GetDirectionWithMaximumDistance() const;
public:
    std::unique_ptr<GhostModeChangeEvent> onModeChange;

    explicit Ghost(const Coordinate2D::NormalizedCoordinate &startPosition, const float &stasisTime=0.0f);
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    void CollideWith(PacMan &) final;

    void CollideWith(PMLogic::Entity &) override;

    void CollideWith(Wall &) override;

    GhostMode GetMode() const;
    void SetMode(const GhostMode &);

    void ChooseDirection() override;

    void ResetViableDirections();

    void Update(const EntityPositionChangeEvent &eventData) override;

    void Update(const EntityCollectedEvent &eventData) override;

    using AutomaticEntity::Update;
};

#endif // PACMAN_GHOST_H
