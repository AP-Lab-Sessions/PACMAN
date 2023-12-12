//

#include "Entity.h"

PMLogic::Entity::Entity(Coordinate2D::NormalizedCoordinate startPosition, const Coordinate2D::Coordinate &size)
    : position(std::move(startPosition)), size(size) {}

Coordinate2D::NormalizedCoordinate PMLogic::Entity::GetPosition() const {
    return position;
}

void PMLogic::Entity::SetPosition(const Coordinate2D::NormalizedCoordinate &newPosition) {
    position = newPosition;
}
void PMLogic::Entity::NotifyAll() {
    for(const auto& currentObserver : observers) {
        currentObserver.lock()->Update();
    }
}

Coordinate2D::Coordinate PMLogic::Entity::GetSize() const {
    return size;
}