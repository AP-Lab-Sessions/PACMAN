//

#include "Camera.h"

Camera::Camera(const unsigned int& width, const unsigned int& height) : width(width), height(height){}

Coordinate2D::PixelCoordinate Camera::Project(const PMLogic::Entity& entity) const {
    return Coordinate2D::Project(entity.GetCurrentPosition(), width, height);
}