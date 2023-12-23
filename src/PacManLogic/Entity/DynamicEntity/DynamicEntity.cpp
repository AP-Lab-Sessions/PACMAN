//

#include "DynamicEntity.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include "Events/EntityEvent/EntityDirectionChangeEvent.h"
#include "Helper/DeltaTime/DeltaTime.h"
#include "Entity/StaticEntity/Intersection/Intersection.h"


DynamicEntity::DynamicEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                             const Coordinate2D::Coordinate &size,
                              const float &defaultSpeed)
    : PMLogic::Entity(startPosition, size), spawn(startPosition),
      currentDirection(Coordinate2D::Direction_Right), nextDirection(currentDirection), viableDirections(Coordinate2D::directions2D),
      defaultSpeed(defaultSpeed), speed(defaultSpeed),
      isKillable(true),
      onPositionChange(std::make_unique<EntityPositionChangeEvent>(startPosition)),
    onDirectionChange(std::make_unique<EntityDirectionChangeEvent>(currentDirection)) {
}

void DynamicEntity::Move() {
    if(std::find(viableDirections.begin(), viableDirections.end(), nextDirection) != viableDirections.end()) {
        SetDirection(nextDirection);
    }
    if(std::find(viableDirections.begin(), viableDirections.end(), GetDirection()) != viableDirections.end()) {
        SetPosition(GetNextPosition());
    }
    viableDirections = Coordinate2D::directions2D;
}

Coordinate2D::NormalizedCoordinate DynamicEntity::GetNextPosition(const Coordinate2D::DiscreteDirection2D& direction) const {
    const float deltaTime {PMLogic::Helper::DeltaTime::GetInstance().lock()->GetDeltaTime()};
    Coordinate2D::NormalizedCoordinate newPosition {GetPosition()};
    switch(direction) {
    case Coordinate2D::Direction_Left:
        newPosition.SetX(Coordinate2D::Normalize(position.GetX()+(-speed)*deltaTime, size.GetX()));
        break;
    case Coordinate2D::Direction_Right:
        newPosition.SetX(Coordinate2D::Normalize(position.GetX()+speed*deltaTime, size.GetX()));
        break;
    case Coordinate2D::Direction_Down:
        newPosition.SetY(Coordinate2D::Normalize(position.GetY()+speed*deltaTime,size.GetY()));
        break;
    case Coordinate2D::Direction_Up:
        newPosition.SetY(Coordinate2D::Normalize(position.GetY()+(-speed)*deltaTime, size.GetY()));
        break;
    default:
        break;
    }
    return newPosition;
}

Coordinate2D::NormalizedCoordinate DynamicEntity::GetNextPosition() const {
    return GetNextPosition(GetDirection());
}
void DynamicEntity::SetPosition(const Coordinate2D::Coordinate &newPosition) {
    const Coordinate2D::NormalizedCoordinate adjustedPosition{Coordinate2D::Normalize(newPosition, GetSize())};
    position = adjustedPosition;
    onPositionChange->newPosition = adjustedPosition;
    onPositionChange->Notify(*onPositionChange);
}
float DynamicEntity::GetSpeed() const {
    return speed;
}

void DynamicEntity::SetSpeed(const float &newSpeed) {
    speed = newSpeed;
}


void DynamicEntity::SetNextDirection(const Coordinate2D::DiscreteDirection2D& newDirection) {
    nextDirection = newDirection;
}
void DynamicEntity::SetDirection(const Coordinate2D::DiscreteDirection2D &newDirection) {
    currentDirection = newDirection;
    onDirectionChange->newDirection = newDirection;
    onDirectionChange->Notify(*onDirectionChange);
}

Coordinate2D::DiscreteDirection2D DynamicEntity::GetDirection() const {
    return currentDirection;
}

bool DynamicEntity::GetIsKillable() const {
    return isKillable;
}

void DynamicEntity::SetIsKillable(const bool &newIsKillable) {
    isKillable = newIsKillable;
}

void DynamicEntity::CollideWith(Wall & wall) {
     if(WillCollide(wall)) {
        const auto &nextPosition {GetNextPosition()};
        switch(GetDirection()) {
        case Coordinate2D::Direction_Right:
            SetPosition({wall.GetPosition().GetX()-GetSize().GetX(), nextPosition.GetY()});
            break;
        case Coordinate2D::Direction_Left:
            SetPosition({wall.GetPosition().GetX()+wall.GetSize().GetX(),nextPosition.GetY()});
            break;
        case Coordinate2D::Direction_Up:
            SetPosition({nextPosition.GetX(), wall.GetPosition().GetY()+wall.GetSize().GetY()});
            break;
        case Coordinate2D::Direction_Down:
            SetPosition({nextPosition.GetX(), wall.GetPosition().GetY()-GetSize().GetY()});
            break;
        }
    }
    for(const auto &direction : Coordinate2D::directions2D) {
        if(WillCollide(wall, direction)) {
            viableDirections.remove(direction);
        }
    }
}
void DynamicEntity::CollideWith(Intersection& intersection) {
    if(WillCollide(intersection) && GetDirection() != nextDirection) {
        const auto &directionsList = intersection.GetDirections();
        if(std::find(directionsList.begin(), directionsList.end(), nextDirection) != directionsList.end()) {
            const auto &nextPosition {GetNextPosition(nextDirection)};
            if(GetPosition().GetX() != nextPosition.GetX()) {
                SetPosition({nextPosition.GetX(), intersection.GetPosition().GetY()});
            }
            else SetPosition({intersection.GetPosition().GetX(), nextPosition.GetY()});
        }
    }
}

bool DynamicEntity::WillCollide(const PMLogic::Entity &entity) const {
    return Coordinate2D::IsOverlapping(GetNextPosition(), GetSize(), entity.GetPosition(), entity.GetSize());
}
bool DynamicEntity::WillCollide(const PMLogic::Entity& entity, const Coordinate2D::DiscreteDirection2D& direction) const {
    return Coordinate2D::IsOverlapping(GetNextPosition(direction), GetSize(), entity.GetPosition(), entity.GetSize());
}

float DynamicEntity::GetDefaultSpeed() const {
    return defaultSpeed;
}

Coordinate2D::NormalizedCoordinate DynamicEntity::GetSpawn() const {
    return spawn;
}


void DynamicEntity::Respawn() {
    SetPosition(GetSpawn());
    onEntityCreate->Notify(*onEntityCreate);
}