//

#include "CollectableEntity.h"


CollectableEntity::CollectableEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                                     const Coordinate2D::Coordinate &size,
                                     const int& reward)
: StaticEntity(startPosition, size), reward(reward),
      onEntityCollected(std::make_unique<EntityCollectedEvent>(GetReward(), false)) {

}

int CollectableEntity::GetReward() const {return reward;}



