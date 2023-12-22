//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Entity/DynamicEntity/AutomaticEntity/AutomaticEntity.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"
#include "Events/EntityEvent/GhostEvent/GhostModeChangeEvent.h"

#include <unordered_map>
#include "Entity/StaticEntity/Intersection/Intersection.h"


enum GhostMode : short {Mode_Stasis, Mode_Chase, Mode_Fear};

class Ghost : public AutomaticEntity,
              public PMLogic::IEventListener<EntityCollectedEvent>
{
private:
    std::shared_ptr<PMLogic::Helper::Timer> modeTimer;
protected:
    const float fearDuration;
    GhostMode mode;

    Coordinate2D::DiscreteDirection2D GetDirectionWithMinimumDistance() const;
    Coordinate2D::DiscreteDirection2D GetDirectionWithMaximumDistance() const;

    std::list<Intersection> collidingWithIntersection;
public:
    std::unique_ptr<GhostModeChangeEvent> onModeChange;
    std::unique_ptr<EntityCollectedEvent> onEntityCollected;

    explicit Ghost(const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size,
                   const float &power, const float &stasisTime=0.0f);
    void Accept(const std::weak_ptr<IEntityVisitor> &visitor) override;

    void CollideWith(PacMan &) final;

    void CollideWith(PMLogic::Entity &) override;

    void CollideWith(Wall &) override;

    void CollideWith(const Intersection &) override;


    GhostMode GetMode() const;
    void SetMode(const GhostMode &);

    void ChooseDirection() override;

    void Update(const EntityPositionChangeEvent &eventData) override;

    void Update(const EntityCollectedEvent &eventData) override;

    using AutomaticEntity::Update;

    void Respawn() override;
};

#endif // PACMAN_GHOST_H
