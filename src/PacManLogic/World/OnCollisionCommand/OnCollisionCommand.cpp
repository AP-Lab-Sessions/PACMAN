//

#include "OnCollisionCommand.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"


OnCollisionCommand::OnCollisionCommand(std::vector<std::reference_wrapper<const PMLogic::Entity>> &destructables)
        : destructables(destructables) {}

void OnCollisionCommand::SetColliders(PacMan &pacMan, Ghost &ghost) {
    if(ghost.GetIsKillable()) {
        ghost.Respawn();
        ghost.onEntityCollected->Notify(*ghost.onEntityCollected);
    }
    else if(pacMan.GetIsKillable()) {
        destructables.emplace_back(pacMan);
    }
}
void OnCollisionCommand::SetColliders(const CollectableEntity &collectable) {
    destructables.emplace_back(collectable);
}

void OnCollisionCommand::Execute() {}

void OnCollisionCommand::ExecuteAndNotify() {Notify(*this);}