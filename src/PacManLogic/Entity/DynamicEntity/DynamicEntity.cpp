//

#include "DynamicEntity.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include "Events/EntityEvent/EntityDirectionChangeEvent.h"
#include "Helper/DeltaTime/DeltaTime.h"

DynamicEntity::DynamicEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                             const Coordinate2D::Coordinate &size,
                              const float &defaultSpeed)
    : PMLogic::Entity(startPosition, size), spawn(startPosition),
      currentDirection(Coordinate2D::Direction_Right), nextDirection(currentDirection), viableDirections(directions2D),
      defaultSpeed(defaultSpeed), speed(defaultSpeed),
      isKillable(true), onPositionChange(std::make_unique<EntityPositionChangeEvent>(startPosition)),
    onDirectionChange(std::make_unique<EntityDirectionChangeEvent>(currentDirection)) {
}

float move(const float &position, const float &speed, const float &length) {
    const float potentialResult {position+speed};
    if(potentialResult+length > Coordinate2D::normalizedMax) {
        return Coordinate2D::normalizedMin;
    }
    else if(potentialResult < Coordinate2D::normalizedMin) {
        return Coordinate2D::normalizedMax-length;
    }
    return potentialResult;
}
void DynamicEntity::Move() {
    if(std::find(viableDirections.begin(), viableDirections.end(), nextDirection) != viableDirections.end()) {
        SetDirection(nextDirection);
    }
    if(std::find(viableDirections.begin(), viableDirections.end(), GetDirection()) != viableDirections.end()) {
        SetPosition(GetNextPosition());
    }
    viableDirections = directions2D;
}

Coordinate2D::NormalizedCoordinate DynamicEntity::GetNextPosition(const Coordinate2D::DiscreteDirection2D& direction) const {
    const float deltaTime {PMLogic::Helper::DeltaTime::GetInstance().lock()->GetDeltaTime()};
    Coordinate2D::NormalizedCoordinate newPosition {GetPosition()};
    switch(direction) {
    case Coordinate2D::Direction_Left:
        newPosition.SetX(move(position.GetX(), -speed*deltaTime, size.GetX()));
        break;
    case Coordinate2D::Direction_Right:
        newPosition.SetX(move(position.GetX(), speed*deltaTime, size.GetX()));
        break;
    case Coordinate2D::Direction_Down:
        newPosition.SetY( move(position.GetY(), speed*deltaTime, size.GetY()));
        break;
    case Coordinate2D::Direction_Up:
        newPosition.SetY(move(position.GetY(), -speed*deltaTime, size.GetY()));
        break;
    default:
        break;
    }
    return newPosition;
}

Coordinate2D::NormalizedCoordinate DynamicEntity::GetNextPosition() const {
    return GetNextPosition(GetDirection());
}
void DynamicEntity::SetPosition(const Coordinate2D::NormalizedCoordinate &newPosition) {
    position = newPosition;
    onPositionChange->newPosition = newPosition;
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
    for(const auto &direction : directions2D) {
        if(WillCollide(wall, direction)) {
            viableDirections.remove(direction);
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