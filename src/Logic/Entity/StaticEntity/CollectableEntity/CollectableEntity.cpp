//

#include "CollectableEntity.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"

PMGame::Logic::CollectableEntity::CollectableEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                                                    const Coordinate2D::Coordinate& size, const int& reward,
                                                    const bool& isFruit)
    : StaticEntity(startPosition, size), reward(reward),
      onEntityCollected(std::make_unique<EntityCollectedEvent>(GetReward(), isFruit)) {}

int PMGame::Logic::CollectableEntity::GetReward() const { return reward; }

void PMGame::Logic::CollectableEntity::CollideWith(const PMGame::Logic::PacMan& pacman) {
    if(WillCollide(pacman)) {
        onEntityCollected->Notify(*onEntityCollected);
        onEntityDestroy->Notify(*onEntityDestroy);
    }
}