//

#include "DynamicEntity.h"
#include "Helper/StopWatch/StopWatch.h"
#include "Entity/StaticEntity/Wall/Wall.h"

DynamicEntity::DynamicEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                             const Coordinate2D::Coordinate &size,
                             const unsigned int &lives, const float &speed)
    : PMLogic::Entity(startPosition, size),lives(lives),  currentDirection(Direction_Right), speed(speed),
    canMove(true), isKillable(true) {}


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
    if(GetCanMove()) {
        const auto nextPosition = GetNextPosition();
        SetPosition(nextPosition);
    }
}

void DynamicEntity::SetCanMove(const bool &newCanMove) {
    canMove = newCanMove;
}

bool DynamicEntity::GetCanMove() const {
    return canMove;
}

Coordinate2D::NormalizedCoordinate DynamicEntity::GetNextPosition() const {
    const float deltaTime = PMLogic::Helper::StopWatch::GetInstance().lock()->GetDeltaTime();
    Coordinate2D::NormalizedCoordinate newPosition = GetPosition();
    switch(currentDirection) {
        case Direction_Left:
            newPosition.SetX(move(position.GetX(), -speed*deltaTime, size.GetX()));
            break;
        case Direction_Right:
            newPosition.SetX(move(position.GetX(), speed*deltaTime, size.GetX()));
            break;
        case Direction_Down:
            newPosition.SetY( move(position.GetY(), speed*deltaTime, size.GetY()));
            break;
        case Direction_Up:
            newPosition.SetY(move(position.GetY(), -speed*deltaTime, size.GetY()));
            break;
        default:
            break;
    }
    return newPosition;
}

float DynamicEntity::GetSpeed() const {
    return speed;
}

void DynamicEntity::SetSpeed(const float &newSpeed) {
    speed = newSpeed;
}

unsigned int DynamicEntity::GetLives() const {
    return lives;
}

void DynamicEntity::SetDirection(const DiscreteDirection2D &newDirection) {
    currentDirection = newDirection;
}

DiscreteDirection2D DynamicEntity::GetDirection() const {
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
        SetCanMove(false);
    }
    else SetCanMove(true);
}

bool DynamicEntity::WillCollide(const PMLogic::Entity &entity) const {
    return Coordinate2D::IsOverlapping(GetNextPosition(), GetSize(), entity.GetPosition(), entity.GetSize());
}
