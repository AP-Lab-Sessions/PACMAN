//

#ifndef PACMAN_ENTITYCOLLISIONCOMMAND_H
#define PACMAN_ENTITYCOLLISIONCOMMAND_H

#include "Pattern/Command/ICommand/ICommand.h"
#include "Entity/DynamicEntity/DynamicEntity.h"

// TODO: based upon isCollider

class EntityOnCollisionCommand : public PMLogic::ICommand {
protected:
    std::weak_ptr<DynamicEntity> entity;
    std::weak_ptr<PMLogic::Entity> collidedWith;
public:
    EntityOnCollisionCommand(const std::weak_ptr<DynamicEntity> &entity,
                             const std::weak_ptr<PMLogic::Entity> &collidedWith);
    void Execute() override;
};


#endif //PACMAN_ENTITYCOLLISIONCOMMAND_H
