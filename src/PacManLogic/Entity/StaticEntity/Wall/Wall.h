//

#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H

#include "Entity/StaticEntity/StaticEntity.h"

class Wall : public StaticEntity {
public:
    Wall();

    void Accept(const std::weak_ptr<PMLogic::IVisitor> &visitor) const override;
};

#endif // PACMAN_WALL_H
