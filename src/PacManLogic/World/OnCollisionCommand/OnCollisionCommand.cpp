//

#include "OnCollisionCommand.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Entity/StaticEntity/CollectableEntity/CollectableEntity.h"


OnCollisionCommand::OnCollisionCommand(std::vector<std::reference_wrapper<const PMLogic::Entity>> &destructables)
        : destructables(destructables) {}

void OnCollisionCommand::SetColliders(const PacMan &pacMan, const Ghost &ghost) {
    if(pacMan.GetIsKillable()) {
        destructables.emplace_back(pacMan);
    }
    else if(ghost.GetIsKillable()) {
        destructables.emplace_back(ghost);
    }
}
void OnCollisionCommand::SetColliders(const CollectableEntity &collectable) {
    destructables.emplace_back(collectable);
}

void OnCollisionCommand::Execute() {}

void OnCollisionCommand::ExecuteAndNotify() {Notify(*this);}