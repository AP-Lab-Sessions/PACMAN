//

#include "CollectableEntity.h"


CollectableEntity::CollectableEntity(const int& reward) : StaticEntity(true, false), reward(reward) {}

int CollectableEntity::GetReward() const {return reward;}

