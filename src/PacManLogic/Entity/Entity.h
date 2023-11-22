//

#ifndef PACMAN_ENTITY_H
#define PACMAN_ENTITY_H

#include "PMLogic.h"
#include "Subject/Subject.h"


class PMLogic::Entity : public PMLogic::Subject<PMLogic::Entity>{
public:
    ~Entity() override = default;
};

#endif // PACMAN_ENTITY_H
