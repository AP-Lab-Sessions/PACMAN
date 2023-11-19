//

#include "EntityViewFactory.h"
std::unique_ptr<EntityView> EntityViewFactory::CreateEntity() const {
    std::unique_ptr<EntityView> entityView(new EntityView());
    return entityView;
}