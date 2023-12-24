//

#include "DynamicEntity.h"
#include "Entity/StaticEntity/Intersection/Intersection.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include "Events/EntityEvent/EntityDirectionChangeEvent.h"
#include "Helper/TimeManager/TimeManager.h"

PMGame::Logic::DynamicEntity::DynamicEntity(const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
                                            const PMGame::Logic::Coordinate2D::Coordinate& size,
                                            const float& defaultSpeed)
    : PMGame::Logic::Entity(startPosition, size), spawn(startPosition),
      currentDirection(PMGame::Logic::Coordinate2D::Direction_Right), nextDirection(currentDirection),
      viableDirections(PMGame::Logic::Coordinate2D::directions2D), defaultSpeed(defaultSpeed), speed(defaultSpeed),
      isKillable(true), onPositionChange(std::make_unique<EntityPositionChangeEvent>(startPosition)),
      onDirectionChange(std::make_unique<EntityDirectionChangeEvent>(currentDirection)) {}

void PMGame::Logic::DynamicEntity::Move() {
    if (std::find(viableDirections.begin(), viableDirections.end(), nextDirection) != viableDirections.end()) {
        SetDirection(nextDirection);
    }
    if (std::find(viableDirections.begin(), viableDirections.end(), GetDirection()) != viableDirections.end()) {
        SetPosition(GetNextPosition());
    }
    viableDirections = PMGame::Logic::Coordinate2D::directions2D;
}

PMGame::Logic::Coordinate2D::NormalizedCoordinate PMGame::Logic::DynamicEntity::GetNextPosition(
    const PMGame::Logic::Coordinate2D::DiscreteDirection2D& direction) const {
    const float deltaTime{PMGame::Logic::Helper::TimeManager::GetInstance().lock()->GetDeltaTime()};
    PMGame::Logic::Coordinate2D::NormalizedCoordinate newPosition{GetPosition()};
    switch (direction) {
    case PMGame::Logic::Coordinate2D::Direction_Left:
        newPosition.SetX(PMGame::Logic::Coordinate2D::Normalize(position.GetX() + (-speed) * deltaTime, size.GetX()));
        break;
    case PMGame::Logic::Coordinate2D::Direction_Right:
        newPosition.SetX(PMGame::Logic::Coordinate2D::Normalize(position.GetX() + speed * deltaTime, size.GetX()));
        break;
    case PMGame::Logic::Coordinate2D::Direction_Down:
        newPosition.SetY(PMGame::Logic::Coordinate2D::Normalize(position.GetY() + speed * deltaTime, size.GetY()));
        break;
    case PMGame::Logic::Coordinate2D::Direction_Up:
        newPosition.SetY(PMGame::Logic::Coordinate2D::Normalize(position.GetY() + (-speed) * deltaTime, size.GetY()));
        break;
    default:
        break;
    }
    return newPosition;
}

PMGame::Logic::Coordinate2D::NormalizedCoordinate PMGame::Logic::DynamicEntity::GetNextPosition() const {
    return GetNextPosition(GetDirection());
}
void PMGame::Logic::DynamicEntity::SetPosition(const PMGame::Logic::Coordinate2D::Coordinate& newPosition) {
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate adjustedPosition{
        PMGame::Logic::Coordinate2D::Normalize(newPosition, GetSize())};
    position = adjustedPosition;
    onPositionChange->newPosition = adjustedPosition;
    onPositionChange->Notify(*onPositionChange);
}
float PMGame::Logic::DynamicEntity::GetSpeed() const { return speed; }

void PMGame::Logic::DynamicEntity::SetSpeed(const float& newSpeed) { speed = newSpeed; }

void PMGame::Logic::DynamicEntity::SetNextDirection(
    const PMGame::Logic::Coordinate2D::DiscreteDirection2D& newDirection) {
    nextDirection = newDirection;
}
void PMGame::Logic::DynamicEntity::SetDirection(const PMGame::Logic::Coordinate2D::DiscreteDirection2D& newDirection) {
    currentDirection = newDirection;
    onDirectionChange->newDirection = newDirection;
    onDirectionChange->Notify(*onDirectionChange);
}

PMGame::Logic::Coordinate2D::DiscreteDirection2D PMGame::Logic::DynamicEntity::GetDirection() const {
    return currentDirection;
}

bool PMGame::Logic::DynamicEntity::GetIsKillable() const { return isKillable; }

void PMGame::Logic::DynamicEntity::SetIsKillable(const bool& newIsKillable) { isKillable = newIsKillable; }

void PMGame::Logic::DynamicEntity::CollideWith(const Wall& wall) {
    if (WillCollide(wall)) {
        const auto& nextPosition{GetNextPosition()};
        switch (GetDirection()) {
        case PMGame::Logic::Coordinate2D::Direction_Right:
            SetPosition({wall.GetPosition().GetX() - GetSize().GetX(), nextPosition.GetY()});
            break;
        case PMGame::Logic::Coordinate2D::Direction_Left:
            SetPosition({wall.GetPosition().GetX() + wall.GetSize().GetX(), nextPosition.GetY()});
            break;
        case PMGame::Logic::Coordinate2D::Direction_Up:
            SetPosition({nextPosition.GetX(), wall.GetPosition().GetY() + wall.GetSize().GetY()});
            break;
        case PMGame::Logic::Coordinate2D::Direction_Down:
            SetPosition({nextPosition.GetX(), wall.GetPosition().GetY() - GetSize().GetY()});
            break;
        }
    }
    for (const auto& direction : PMGame::Logic::Coordinate2D::directions2D) {
        if (WillCollide(wall, direction)) {
            viableDirections.remove(direction);
        }
    }
}
void PMGame::Logic::DynamicEntity::CollideWith(const Intersection& intersection) {
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate centeredCoord =
        PMGame::Logic::Coordinate2D::GetCenteredShrinked(intersection.GetPosition(), intersection.GetSize(), 10);
    if (PMGame::Logic::Coordinate2D::IsOverlapping(
            centeredCoord, {intersection.GetSize().GetX() / 10, intersection.GetSize().GetY() / 10}, GetNextPosition(),
            GetSize()) &&
        GetDirection() != nextDirection) {
        const auto& directionsList = intersection.GetDirections();
        if (std::find(directionsList.begin(), directionsList.end(), nextDirection) != directionsList.end()) {
            const auto& nextPosition{GetNextPosition(nextDirection)};
            if (GetPosition().GetX() != nextPosition.GetX()) {
                SetPosition({nextPosition.GetX(), intersection.GetPosition().GetY()});
            } else
                SetPosition({intersection.GetPosition().GetX(), nextPosition.GetY()});
        }
    }
}

bool PMGame::Logic::DynamicEntity::WillCollide(const PMGame::Logic::Entity& entity) const {
    return PMGame::Logic::Coordinate2D::IsOverlapping(GetNextPosition(), GetSize(), entity.GetPosition(),
                                                      entity.GetSize());
}
bool PMGame::Logic::DynamicEntity::WillCollide(
    const PMGame::Logic::Entity& entity, const PMGame::Logic::Coordinate2D::DiscreteDirection2D& direction) const {
    return PMGame::Logic::Coordinate2D::IsOverlapping(GetNextPosition(direction), GetSize(), entity.GetPosition(),
                                                      entity.GetSize());
}

float PMGame::Logic::DynamicEntity::GetDefaultSpeed() const { return defaultSpeed; }

PMGame::Logic::Coordinate2D::NormalizedCoordinate PMGame::Logic::DynamicEntity::GetSpawn() const { return spawn; }

void PMGame::Logic::DynamicEntity::Respawn() {
    SetPosition(GetSpawn());
    onEntityCreate->Notify(*onEntityCreate);
}