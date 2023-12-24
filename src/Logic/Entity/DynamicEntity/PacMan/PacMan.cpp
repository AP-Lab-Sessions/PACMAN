//

#include "PacMan.h"

#include "Entity/IEntityVisitor/IEntityVisitor.h"
#include "Entity/StaticEntity/CollectableEntity/Coin/Coin.h"
#include "Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"

PMGame::Logic::PacMan::PacMan(const Coordinate2D::NormalizedCoordinate& startPosition,
                              const Coordinate2D::Coordinate& size)
    : DynamicEntity(startPosition, size, 0.75f) {
    SetIsKillable(true);
}

void PMGame::Logic::PacMan::Accept(const std::weak_ptr<IEntityVisitor>& visitor) { visitor.lock()->Visit(*this); }


void PMGame::Logic::PacMan::CollideWith(PMGame::Logic::Entity& entity) const { entity.CollideWith(*this); }

void PMGame::Logic::PacMan::CollideWith(const PMGame::Logic::Ghost& ghost) {
    if(WillCollide(ghost)) {
        if (!ghost.GetIsKillable() && GetIsKillable()) {
            onEntityDestroy->Notify(*onEntityDestroy);
        }
    }
}