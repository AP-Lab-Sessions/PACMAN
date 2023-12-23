//

#ifndef PACMAN_CAMERA_H
#define PACMAN_CAMERA_H

#include "Entity/Entity.h"
#include "Coordinate/Coordinate.h"
#include "PMLogic.h"

/**
* @brief Helps with projecting the normalized positions and sizes of the entities given a width and height
 */
class PMLogic::Helper::Camera {
protected:
    unsigned int width, height;
public:
    /**
     *
     * @param width The width of the window to project to
     * @param height The height of the window to project to
     */
    Camera(const unsigned int &width, const unsigned int &height);
    /**
     *  @brief Projects a non-normalized coordinate (used for size of entity)
     * @param coordinate
     * @return The projected coordinate
     */
    Coordinate2D::Coordinate ProjectSize(const Coordinate2D::Coordinate &coordinate) const;
    /**
     * @brief Projects a normalized coordinate (used for position of entity)
     * @param coordinate
     * @return The projected coordinate
     */
    Coordinate2D::Coordinate Project(const Coordinate2D::NormalizedCoordinate &coordinate) const;
};

#endif // PACMAN_CAMERA_H
