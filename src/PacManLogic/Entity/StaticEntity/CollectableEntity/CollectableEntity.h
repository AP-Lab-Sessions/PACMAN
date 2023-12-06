//

#ifndef PACMAN_COLLECTABLEENTITY_H
#define PACMAN_COLLECTABLEENTITY_H

#include "Entity/StaticEntity/StaticEntity.h"

class CollectableEntity : public StaticEntity {
protected:
    int reward;
public:
    ~CollectableEntity() override = default;
    CollectableEntity(const int &reward);

    int GetReward() const;
};

#endif // PACMAN_COLLECTABLEENTITY_H
