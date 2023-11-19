//

#ifndef PAC_MAN_ENTITYVIEWFACTORY_H
#define PAC_MAN_ENTITYVIEWFACTORY_H

#include "EntityFactory/EntityFactory.h"
#include "EntityView/EntityView.h"

/**
 * @brief A class derived from EntityFactory where the entity type is now non-generic base class EntityView
 */
class EntityViewFactory : public EntityFactory<EntityView> {
public:
    /**
     * @brief Creates an EntityView object and gives away its ownership
     * @return Unique pointer to an EntityView object
     */
    std::unique_ptr<EntityView> CreateEntity() const override;
};

#endif // PAC_MAN_ENTITYVIEWFACTORY_H
