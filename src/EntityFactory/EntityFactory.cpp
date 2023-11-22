//

#include "EntityFactory.h"
#include "EntityView/EntityView.h"

std::unique_ptr<PMLogic::Entity> EntityFactory::Create() const {
    std::unique_ptr<PMLogic::Entity> entity{new PMLogic::Entity()};
    std::shared_ptr<EntityView> entityView{new EntityView()};
    entity->Attach(entityView);
    return entity;
}