//

#include "PacMan.h"

#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"

PacMan::PacMan(const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size) :
DynamicEntity(startPosition, size, 0.75f) {
    SetIsKillable(true);
}

void PacMan::Eat(const CollectableEntity& collectable) {
    collectable.onEntityCollected->Notify(*collectable.onEntityCollected);
    collectable.onEntityDestroy->Notify(*collectable.onEntityDestroy);
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

void PacMan::CollideWith(Ghost &ghost) {
}

void PacMan::CollideWith(PMLogic::Entity &entity) {
    entity.CollideWith(*this);
}