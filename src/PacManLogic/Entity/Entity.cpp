//

#include "Entity.h"

PMLogic::Entity::Entity(Coordinate2D::NormalizedCoordinate startPosition)
    : startPosition(std::move(startPosition)) {}

PMLogic::Entity::Entity() : startPosition({0,0}) {}

Coordinate2D::NormalizedCoordinate PMLogic::Entity::GetStartPosition() const {
    return startPosition;
}

Coordinate2D::NormalizedCoordinate PMLogic::Entity::GetCurrentPosition() const {
    return GetStartPosition();
}

void PMLogic::Entity::NotifyAll() {
    for(const auto& currentObserver : observers) {
        currentObserver.lock()->Update();
    }
}
