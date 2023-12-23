//

#include "Camera.h"

PMLogic::Helper::Camera::Camera(const unsigned int& width, const unsigned int& height) : width(width), height(height) {}

Coordinate2D::Coordinate PMLogic::Helper::Camera::ProjectSize(const Coordinate2D::Coordinate& coordinate) const {
    return {static_cast<float>(width) * coordinate.GetX() / 2, static_cast<float>(height) * coordinate.GetY() / 2};
}

Coordinate2D::Coordinate PMLogic::Helper::Camera::Project(const Coordinate2D::NormalizedCoordinate& coordinate) const {
    const float x = static_cast<float>(width) / 2 * (coordinate.GetX() + 1);
    const float y = static_cast<float>(height) / 2 * (coordinate.GetY() + 1);
    return {x, y};
}