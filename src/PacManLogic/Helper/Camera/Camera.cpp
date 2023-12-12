//

#include "Camera.h"

PMLogic::Helper::Camera::Camera(const unsigned int& width, const unsigned int& height) : width(width), height(height){}

Coordinate2D::Coordinate PMLogic::Helper::Camera::ProjectCurrentPosition(const PMLogic::Entity& entity) const {
    return Coordinate2D::Project(entity.GetPosition(), width, height);
}

Coordinate2D::Coordinate PMLogic::Helper::Camera::ProjectSize(const PMLogic::Entity &entity) const {
    return {static_cast<float>(width)*entity.GetSize().GetX()/2,
            static_cast<float>(height)*entity.GetSize().GetY()/2};
}