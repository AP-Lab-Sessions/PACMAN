//

#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H

#include "PMLogic.h"
#include "AbstractFactory/AbstractFactory.h"
#include "Entity/Entity.h"
#include "EntityView/EntityView.h"

template<typename DerivedEntity>
class EntityFactory : public PMLogic::AbstractFactory<PMLogic::Entity> {
public:
    std::unique_ptr<PMLogic::Entity> Create() const override {
        std::unique_ptr<DerivedEntity> entity{new DerivedEntity()};
        std::shared_ptr<EntityView> entityView{new EntityView()};
        entity->Attach(entityView);
        return entity;
    }
    ~EntityFactory() override = default;
};

#endif // PACMAN_ENTITYFACTORY_H
