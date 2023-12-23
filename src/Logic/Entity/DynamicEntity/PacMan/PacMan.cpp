//

#include "PacMan.h"

#include "Entity/IEntityVisitor/IEntityVisitor.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"

PMGame::Logic::PacMan::PacMan(const Coordinate2D::NormalizedCoordinate& startPosition,
                              const Coordinate2D::Coordinate& size)
    : DynamicEntity(startPosition, size, 0.75f) {
    SetIsKillable(true);
}

void PMGame::Logic::PacMan::Eat(const CollectableEntity& collectable) {
    collectable.onEntityCollected->Notify(*collectable.onEntityCollected);
    collectable.onEntityDestroy->Notify(*collectable.onEntityDestroy);
}
void PMGame::Logic::PacMan::Accept(const std::weak_ptr<IEntityVisitor>& visitor) { visitor.lock()->Visit(*this); }

void PMGame::Logic::PacMan::CollideWith(Coin& coin) {
    if (WillCollide(coin)) {
        Eat(coin);
    }
}

void PMGame::Logic::PacMan::CollideWith(Fruit& fruit) {
    if (WillCollide(fruit)) {
        Eat(fruit);
    }
}

void PMGame::Logic::PacMan::CollideWith(PMGame::Logic::Entity& entity) { entity.CollideWith(*this); }