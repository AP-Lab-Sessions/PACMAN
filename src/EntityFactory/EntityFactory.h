//

#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H

#include "PMLogic.h"
#include "AbstractFactory/AbstractFactory.h"
#include "Entity/Entity.h"

class EntityFactory : public PMLogic::AbstractFactory<PMLogic::Entity> {
public:
    std::unique_ptr<PMLogic::Entity> Create() const override;
    ~EntityFactory() override = default;
};

#endif // PACMAN_ENTITYFACTORY_H
