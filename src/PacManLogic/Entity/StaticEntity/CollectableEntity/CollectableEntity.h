//

#ifndef PACMAN_COLLECTABLEENTITY_H
#define PACMAN_COLLECTABLEENTITY_H

#include "Entity/StaticEntity/StaticEntity.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"

class CollectableEntity : public StaticEntity {
protected:
    int reward;
public:
    std::unique_ptr<EntityCollectedEvent> onEntityCollected;

    ~CollectableEntity() override = default;

    CollectableEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                      const Coordinate2D::Coordinate &size, const int &reward,
                      const bool &isFruit=false);

    int GetReward() const;
};

#endif // PACMAN_COLLECTABLEENTITY_H
