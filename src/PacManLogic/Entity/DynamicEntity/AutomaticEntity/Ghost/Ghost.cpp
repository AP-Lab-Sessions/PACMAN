//

#include "Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include "Helper/Random/Random.h"

Ghost::Ghost(const Coordinate2D::NormalizedCoordinate &startPosition) :
DynamicEntity(startPosition, {0.15f,0.15f}, 1, 0.9f), mode(Mode_Stasis)
{
    ResetViableDirections();
    SetIsKillable(false);
}

void Ghost::Accept(const std::weak_ptr<IEntityVisitor>& visitor) {
    visitor.lock()->Visit(*this);
}

void Ghost::CollideWith(PacMan &pacMan) {
    if(WillCollide(pacMan)) {
        if (onCollision)
            onCollision->SetColliders(pacMan, *this);
    }
}

void Ghost::CollideWith(PMLogic::Entity &entity) {
    entity.CollideWith(*this);
}

void Ghost::CollideWith(Wall& wall) {
    if(WillCollide(wall)) {
        switch(mode) {
        case Mode_Stasis:
            TurnOppositeDirection();
            break;
        default:
            viableDirections[GetDirection()] = false;
        }
    }
}

GhostMode Ghost::GetMode() const {
    return mode;
}

void Ghost::SetMode(const GhostMode &newMode) {
    mode = newMode;
    if(GetMode() == Mode_Fear) {
        TurnOppositeDirection();
        SetSpeed(GetDefaultSpeed()/1.5f);
    }
}

void Ghost::ResetViableDirections() {
    std::array<DiscreteDirection2D, 4> directions2D = {Direction_Left, Direction_Right, Direction_Up, Direction_Down};
    for(const auto &currentDirection : directions2D) {
        viableDirections[currentDirection] = true;
    }
}


DiscreteDirection2D Ghost::GetDirectionWithMinimumDistance() const {
    float minDistance = 0.0f;
    const auto &random = PMLogic::Helper::Random::GetInstance();

    DiscreteDirection2D result;
    for(const auto &currentViableDirection : viableDirections) {
        const float currentDistance =
            Coordinate2D::GetManhattanDistance(GetNextPosition(currentViableDirection.first), *target);
        const bool keepPrevious = random.lock()->GetRandomFloat(0.0f, 1.0f) <= 0.5f;
        if(minDistance < currentDistance || !keepPrevious) {
            minDistance = currentDistance;
            result = currentViableDirection.first;
        }
    }
    return result;
}

DiscreteDirection2D Ghost::GetDirectionWithMaximumDistance() const {
    float maxDistance = 0.0f;
    const auto &random = PMLogic::Helper::Random::GetInstance();

    DiscreteDirection2D result;
    for(const auto &currentViableDirection : viableDirections) {
        const float currentDistance =
            Coordinate2D::GetManhattanDistance(GetNextPosition(currentViableDirection.first), *target);
        const bool keepPrevious = random.lock()->GetRandomFloat(0.0f, 1.0f) <= 0.5f;
        if(maxDistance > currentDistance || !keepPrevious) {
            maxDistance = currentDistance;
            result = currentViableDirection.first;
        }
    }
    return result;
}
void Ghost::ChooseDirection() {
    if(GetMode() != Mode_Stasis) {
        const auto& random = PMLogic::Helper::Random::GetInstance();
        const bool computeManhattanDistance = random.lock()->GetRandomFloat(0.0f, 1.0f) <= 0.5f;
        DiscreteDirection2D bestDirection;

        if (!target || !computeManhattanDistance) {
            auto directionIter = viableDirections.begin();
            std::advance(directionIter,
                         random.lock()->GetRandomInteger(0, static_cast<int>(viableDirections.size()) - 1));
            bestDirection = directionIter->first;
        } else {
            switch (mode) {
            case Mode_Chase:
                bestDirection = GetDirectionWithMinimumDistance();
                break;
            default:
                bestDirection = GetDirectionWithMaximumDistance();
                break;
            }
        }
        SetDirection(bestDirection);
        ResetViableDirections();
    }
}

void Ghost::Update(const EntityPositionChangeEvent& eventData) {
    Coordinate2D::NormalizedCoordinate position = eventData.newPosition;
    if(!target) {
        target = std::make_unique<Coordinate2D::NormalizedCoordinate>(position);
    }
    else *target = position;
}