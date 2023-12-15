//

#include "Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include "Helper/Random/Random.h"


Ghost::Ghost(const Coordinate2D::NormalizedCoordinate &startPosition) :
AutomaticEntity(startPosition, {0.1f,0.1f}, 1, 0.7f), mode(Mode_Chase)
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
        viableDirections[GetDirection()] = false;
        ChooseDirection();
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
    else {
        SetSpeed(GetDefaultSpeed());
    }
}

void Ghost::ResetViableDirections() {
    std::array<DiscreteDirection2D, 4> directions2D = {Direction_Left, Direction_Right, Direction_Up, Direction_Down};
    for(const auto &currentDirection : directions2D) {
        viableDirections[currentDirection] = true;
    }
}


DiscreteDirection2D Ghost::GetDirectionWithMinimumDistance() const {
    float minDistance = Coordinate2D::GetManhattanDistance(GetNextPosition(viableDirections.begin()->first), *target);
    const auto random = PMLogic::Helper::Random::GetInstance();

    std::vector<DiscreteDirection2D> result;
    for(const auto &currentViableDirection : viableDirections) {
        const float currentDistance =
            Coordinate2D::GetManhattanDistance(GetNextPosition(currentViableDirection.first), *target);
        if(minDistance > currentDistance) {
            minDistance = currentDistance;
            result.clear();
            result.push_back(currentViableDirection.first);
        }
        else if(minDistance == currentDistance) {
            result.push_back(currentViableDirection.first);
        }
    }
    return result[random.lock()->GetRandomInteger(0, static_cast<int>(result.size()-1))];
}

DiscreteDirection2D Ghost::GetDirectionWithMaximumDistance() const {
    float maxDistance = Coordinate2D::GetManhattanDistance(GetNextPosition(viableDirections.begin()->first), *target);
    const auto random = PMLogic::Helper::Random::GetInstance();

    std::vector<DiscreteDirection2D> result;
    for(const auto &currentViableDirection : viableDirections) {
        const float currentDistance =
            Coordinate2D::GetManhattanDistance(GetNextPosition(currentViableDirection.first), *target);
        if(maxDistance < currentDistance) {
            maxDistance = currentDistance;
            result.clear();
            result.push_back(currentViableDirection.first);
        }
        else if(maxDistance == currentDistance) {
            result.push_back(currentViableDirection.first);
        }
    }
    return result[random.lock()->GetRandomInteger(0, static_cast<int>(result.size()-1))];
}
void Ghost::ChooseDirection() {
        const auto& random = PMLogic::Helper::Random::GetInstance();
        const bool computeManhattanDistance = random.lock()->GetRandomFloat(0.0f, 1.0f) <= 0.5f;
        DiscreteDirection2D bestDirection;

        if (!target || !computeManhattanDistance || GetMode() == Mode_Stasis) {
            auto directionIter = viableDirections.begin();
            const int advancer = random.lock()->GetRandomInteger(0, static_cast<int>(viableDirections.size()-1));
            std::advance(directionIter,advancer);
            bestDirection = directionIter->first;
        } else {
            switch (mode) {
            case Mode_Chase:
                bestDirection = GetDirectionWithMinimumDistance();
                break;
            default:
                bestDirection = GetDirectionWithMaximumDistance();
            }
         }
        SetDirection(bestDirection);
        ResetViableDirections();
}

void Ghost::Update(const EntityPositionChangeEvent& eventData) {
    Coordinate2D::NormalizedCoordinate position = eventData.newPosition;
    if(!target) {
        target = std::make_unique<Coordinate2D::NormalizedCoordinate>(position);
    }
    else *target = position;
}