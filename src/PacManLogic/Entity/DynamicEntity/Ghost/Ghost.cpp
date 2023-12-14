//

#include "Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"

Ghost::Ghost(const Coordinate2D::NormalizedCoordinate &startPosition) :
DynamicEntity(startPosition, {0.15f,0.15f}, 1, 0.9f), mode(Mode_Normal) {
    SetIsKillable(false);
    SetIsCollider(true);
}

void Ghost::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}

void Ghost::CollideWith(PacMan &pacMan) {
    if(WillCollide(pacMan)) {
        if(onCollision) onCollision->SetColliders(pacMan, *this);
    }
}

void Ghost::CollideWith(PMLogic::Entity &entity) {
    entity.CollideWith(*this);
}