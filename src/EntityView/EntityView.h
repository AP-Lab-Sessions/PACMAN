//

#ifndef PACMAN_ENTITYVIEW_H
#define PACMAN_ENTITYVIEW_H

#include "PMLogic.h"
#include "Entity/Entity.h"

class EntityView : public PMLogic::Observer<PMLogic::Entity>{
public:
    void Update(const PMLogic::Entity &entity) override;
    ~EntityView() override = default;
};

#endif // PACMAN_ENTITYVIEW_H
