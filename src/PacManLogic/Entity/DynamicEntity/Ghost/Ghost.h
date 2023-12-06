//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include "Entity/DynamicEntity/DynamicEntity.h"

class Ghost : public DynamicEntity{
public:
    void Accept(const std::weak_ptr<PMLogic::IVisitor> &visitor) const override;
};

#endif // PACMAN_GHOST_H
