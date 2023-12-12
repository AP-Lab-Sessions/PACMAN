//

#include "EntityOnCollisionCommand.h"

EntityOnCollisionCommand::EntityOnCollisionCommand(const std::weak_ptr<DynamicEntity> &entity,
                                                   const std::weak_ptr<PMLogic::Entity> &collidedWith) : entity(entity),
                                               collidedWith(collidedWith)
                                               {}

void EntityOnCollisionCommand::Execute() {

}