//

#include "DynamicEntity.h"
#include "Helper/StopWatch/StopWatch.h"


DynamicEntity::DynamicEntity(const Coordinate2D::NormalizedCoordinate& startPosition,
                             const Coordinate2D::Coordinate &size,
                             const unsigned int &lives, const float &speed)
    : PMLogic::Entity(startPosition, size),lives(lives),  currentDirection(Direction_Right), speed(speed) {}


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
    SetPosition(GetNextPosition());
    PMLogic::Entity::NotifyAll();
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