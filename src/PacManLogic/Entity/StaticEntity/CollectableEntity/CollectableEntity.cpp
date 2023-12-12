//

#include "CollectableEntity.h"


CollectableEntity::CollectableEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                                     const Coordinate2D::Coordinate &size,
                                     const int& reward)
: StaticEntity(startPosition, size, true, false), reward(reward) {}

int CollectableEntity::GetReward() const {return reward;}

