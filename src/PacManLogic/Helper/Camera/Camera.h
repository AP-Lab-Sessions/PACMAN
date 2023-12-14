//

#ifndef PACMAN_CAMERA_H
#define PACMAN_CAMERA_H

#include "Entity/Entity.h"
#include "Coordinate/Coordinate.h"
#include "PMLogic.h"

class PMLogic::Helper::Camera {
protected:
    unsigned int width, height;
public:
    Camera(const unsigned int &width, const unsigned int &height);
    Coordinate2D::Coordinate ProjectCurrentPosition(const PMLogic::Entity &entity) const;
    Coordinate2D::Coordinate ProjectSize(const PMLogic::Entity &entity) const;
    Coordinate2D::Coordinate Project(const Coordinate2D::NormalizedCoordinate &coordinate) const;
};

#endif // PACMAN_CAMERA_H
