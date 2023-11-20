//

#ifndef PAC_MAN_COLLECTABLE_H
#define PAC_MAN_COLLECTABLE_H

#include "Subject/Subject.h"
#include "PMLogic.h"

using namespace PMLogic;
    class Entity::Collectable : public ::Subject<Entity::Collectable> {
public:
    ~Collectable() override = default;
};

#endif // PAC_MAN_COLLECTABLE_H
