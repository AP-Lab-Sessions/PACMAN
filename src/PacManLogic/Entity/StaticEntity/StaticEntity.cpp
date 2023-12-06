//

#include "StaticEntity.h"

StaticEntity::StaticEntity(const bool& isCollectable, const bool& isCollider)
    : isCollectable(isCollectable), isCollider(isCollider) {}

bool StaticEntity::GetIsCollectable() const {return isCollectable;}

bool StaticEntity::GetIsCollider() const {return isCollider;}

