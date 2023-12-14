//

#ifndef PACMAN_ENTITYONCOLLISIONCOMMAND_H
#define PACMAN_ENTITYONCOLLISIONCOMMAND_H

#include "Pattern/Command/ICommand/ICommand.h"
#include "Entity/DynamicEntity/DynamicEntity.h"

template<typename DynamicEntityType, typename EntityType>
class OnCollisionCommand : public PMLogic::ICommand {
protected:
    std::weak_ptr<DynamicEntityType> entity;
    std::weak_ptr<EntityType> collidedWith;
public:
    OnCollisionCommand(const std::weak_ptr<DynamicEntityType> &entity,
                       const std::weak_ptr<EntityType> &collidedWith) : entity(entity), collidedWith(collidedWith)
                             {}
    void Execute() override;
};


#endif //PACMAN_ENTITYONCOLLISIONCOMMAND_H
