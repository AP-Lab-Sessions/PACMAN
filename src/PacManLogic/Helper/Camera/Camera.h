//

#ifndef PACMAN_CAMERA_H
#define PACMAN_CAMERA_H

#include "Entity/Entity.h"
#include "Coordinate/Coordinate.h"

class Camera {
protected:
    unsigned int width, height;
public:
    Camera(const unsigned int &width, const unsigned int &height);
    Coordinate2D::PixelCoordinate Project(const PMLogic::Entity &entity) const;
};

#endif // PACMAN_CAMERA_H
