//

#include "PacMan.h"

#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"

PacMan::PacMan(const Coordinate2D::NormalizedCoordinate &startPosition) :
DynamicEntity(startPosition, {0.1f,0.1f}, 3, 0.75f) {
    SetIsKillable(true);
}

void PacMan::Eat(const CollectableEntity& collectable) {
    onCollision->SetColliders(collectable);
    collectable.onEntityCollected->Notify(*collectable.onEntityCollected);
}
void PacMan::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}

void PacMan::CollideWith(Coin & coin) {
    if(WillCollide(coin)) {
        Eat(coin);
    }
}

void PacMan::CollideWith(Fruit & fruit) {
    if(WillCollide(fruit)) {
        Eat(fruit);
    }
}

void PacMan::CollideWith(Ghost &ghost) {}

void PacMan::CollideWith(PMLogic::Entity &entity) {
    entity.CollideWith(*this);
}