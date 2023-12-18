//

#include "Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include "Helper/Random/Random.h"
#include "Helper/DeltaTime/DeltaTime.h"

const std::list<DiscreteDirection2D> directions2D = {Direction_Left, Direction_Right, Direction_Up, Direction_Down};

Ghost::Ghost(const Coordinate2D::NormalizedCoordinate &startPosition,const Coordinate2D::Coordinate &size,
             const float &power,
             const float &stasisTime) :
AutomaticEntity(startPosition, size, 1, 0.75f*power),  fearDuration(10.0f/power), mode(Mode_Stasis),
    onModeChange(std::make_unique<GhostModeChangeEvent>(mode)),
    onEntityCollected(std::make_unique<EntityCollectedEvent>(50,false))
{
    ResetViableDirections();
    SetIsKillable(false);
    modeTimer = std::make_shared<PMLogic::Helper::Timer>([&]{
                    SetMode(Mode_Chase);
                }, stasisTime);
    PMLogic::Helper::DeltaTime::GetInstance().lock()->AddTimer(modeTimer);
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
    DynamicEntity::WillCollide(wall);
    for(const auto &direction : directions2D) {
        if(WillCollide(wall, direction)) {
            viableDirections.remove(direction);
        }
    }
    if(WillCollide(wall)) ChooseDirection();
}

GhostMode Ghost::GetMode() const {
    return mode;
}

void Ghost::SetMode(const GhostMode &newMode) {
    mode = newMode;
    switch(GetMode()) {
    case Mode_Fear: {
        SetIsKillable(true);
        SetSpeed(GetDefaultSpeed() / 1.5f);
        modeTimer = std::make_shared<PMLogic::Helper::Timer>([&]{
            SetMode(Mode_Chase);
        }, fearDuration);
        PMLogic::Helper::DeltaTime::GetInstance().lock()->AddTimer(modeTimer);
        ChooseDirection();
        break;
    }
    default: {
        SetSpeed(GetDefaultSpeed());
        SetIsKillable(false);
        break;
    }
    }
    onModeChange->newMode = newMode;
    onModeChange->Notify(*onModeChange);
}

void Ghost::ResetViableDirections() {
    viableDirections = directions2D;
}


DiscreteDirection2D Ghost::GetDirectionWithMinimumDistance() const {
    float minDistance = Coordinate2D::GetManhattanDistance(GetNextPosition(*viableDirections.begin()), *target);
    const auto random = PMLogic::Helper::Random::GetInstance();

    std::vector<DiscreteDirection2D> result;
    for(const auto &currentViableDirection : viableDirections) {
        const float currentDistance =
            Coordinate2D::GetManhattanDistance(GetNextPosition(currentViableDirection), *target);
        if(minDistance > currentDistance) {
            minDistance = currentDistance;
            result.clear();
            result.push_back(currentViableDirection);
        }
        else if(minDistance == currentDistance) {
            result.push_back(currentViableDirection);
        }
    }
    return result[random.lock()->GetRandomInteger(0, static_cast<int>(result.size()-1))];
}

DiscreteDirection2D Ghost::GetDirectionWithMaximumDistance() const {
    float maxDistance = Coordinate2D::GetManhattanDistance(GetNextPosition(*viableDirections.begin()), *target);
    const auto random = PMLogic::Helper::Random::GetInstance();

    std::vector<DiscreteDirection2D> result;
    for(const auto &currentViableDirection : viableDirections) {
        const float currentDistance =
            Coordinate2D::GetManhattanDistance(GetNextPosition(currentViableDirection), *target);
        if(maxDistance < currentDistance) {
            maxDistance = currentDistance;
            result.clear();
            result.push_back(currentViableDirection);
        }
        else if(maxDistance == currentDistance) {
            result.push_back(currentViableDirection);
        }
    }
    return result[random.lock()->GetRandomInteger(0, static_cast<int>(result.size()-1))];
}
void Ghost::ChooseDirection() {
    viableDirections.remove(currentDirection);
    if(!viableDirections.empty()) {
        const auto& random = PMLogic::Helper::Random::GetInstance();
        const bool computeManhattanDistance = random.lock()->GetRandomFloat(0.0f, 1.0f) <= 0.5f;
        DiscreteDirection2D bestDirection;

        if (!target || !computeManhattanDistance || GetMode() == Mode_Stasis) {
            auto directionIter = viableDirections.begin();
            const int advancer = random.lock()->GetRandomInteger(0, static_cast<int>(viableDirections.size() - 1));
            std::advance(directionIter, advancer);
            bestDirection = *directionIter;
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
    }
    else SetCanMove(false);
}

void Ghost::Update(const EntityPositionChangeEvent& eventData) {
    Coordinate2D::NormalizedCoordinate position = eventData.newPosition;
    if(!target) {
        target = std::make_unique<Coordinate2D::NormalizedCoordinate>(position);
    }
    else *target = position;
}

void Ghost::Update(const EntityCollectedEvent& eventData) {
    if(eventData.collectedFruit) {
        SetMode(Mode_Fear);
    }
}

void Ghost::Respawn() {
    SetMode(Mode_Chase);
    SetPosition(GetSpawn());
    ChooseDirection();
}