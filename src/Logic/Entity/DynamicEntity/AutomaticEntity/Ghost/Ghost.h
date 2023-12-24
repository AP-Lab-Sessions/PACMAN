//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Entity/DynamicEntity/AutomaticEntity/AutomaticEntity.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"
#include "Events/EntityEvent/GhostEvent/GhostModeChangeEvent.h"

#include "Entity/StaticEntity/Intersection/Intersection.h"
#include "Helper/TimeManager/TimeManager.h"
#include <unordered_map>

namespace PMGame::Logic {
/**
 * @brief The modes that a ghost can be in.
 */
enum GhostMode : short { Mode_Stasis, Mode_Chase, Mode_Fear };

/**
 * @brief The Ghost entity.
 */
class Ghost : public AutomaticEntity, public IEventListener<EntityCollectedEvent> {
private:
    /**
     * @brief Timer used for switching between ghost modes.
     */
    std::shared_ptr<Helper::Timer> modeTimer;

protected:
    /**
     * @brief Duration of fear ghostmode.
     */
    const float fearDuration;

    /**
     * @brief Duration of stasis mode.
     */
    const float stasisDuration;
    /**
     * @brief Current ghost mode.
     */
    GhostMode mode;

    /**
     * @brief Gets the direction with the minimum manhattan distance to the target
     * @return the direction.
     */
    Coordinate2D::DiscreteDirection2D GetDirectionWithMinimumDistance() const;
    /**
     * @brief Gets the direction with the maximal manhattan distance to the target
     * @return the direction.
     */
    Coordinate2D::DiscreteDirection2D GetDirectionWithMaximumDistance() const;

    /**
     * @brief List of intersections the ghost is currently colliding with.
     */
    std::list<Intersection> collidingWithIntersection;

public:
    std::unique_ptr<GhostModeChangeEvent> onModeChange;
    std::unique_ptr<EntityCollectedEvent> onEntityCollected;

    /**
     *
     * @param startPosition The starting position.
     * @param size The size.
     * @param power The power (used by speed)
     * @param stasisTime The duration of the stasis mode.
     */
    explicit Ghost(const Coordinate2D::NormalizedCoordinate& startPosition, const Coordinate2D::Coordinate& size,
                   const float& power, const float& stasisTime = 0.0f);

    /**
     * @brief Calls the visit function of the visitor
     * @param visitor
     */
    void Accept(const std::weak_ptr<IEntityVisitor>& visitor) override;

    /**
     * @brief Handle collision with itself and pacman
     */
    void CollideWith(const PacMan&) final;

    /**
     * @brief Handle collision with itself and an entity.
     */
    void CollideWith(Entity&) const override;

    /**
     * @brief Handle collision with itself and wall.
     */
    void CollideWith(const Wall&) override;

    /**
     * @brief Handle collision with itself and intersection.
     */
    void CollideWith(const Intersection&) override;

    /**
     * @brief Get the ghost mode.
     * @return The ghost mode.
     */
    GhostMode GetMode() const;

    /**
     * @brief Set the ghost mode.
     * @param newMode The new ghost mode.
     */
    void SetMode(const GhostMode& newMode);

    /**
     * @brief Choose the next direction.
     */
    void ChooseNextDirection() override;

    /**
     * @brief Called when the position of pacman has changed and does something with it.
     * @param eventData Information about the position change.
     */
    void Update(const EntityPositionChangeEvent& eventData) override;

    /**
     * @brief Called when pacman eats a collectable, if pacman ate a fruit then the ghost changes mode to fear.
     * @param eventData
     */
    void Update(const EntityCollectedEvent& eventData) override;

    using AutomaticEntity::Update;

    /**
     * @brief Respawns.
     */
    void Respawn() override;
};
} // namespace PMGame::Logic

#endif // PACMAN_GHOST_H
