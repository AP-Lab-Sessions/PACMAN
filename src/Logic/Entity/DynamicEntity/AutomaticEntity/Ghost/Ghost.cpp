//

#include "Ghost.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/IEntityVisitor/IEntityVisitor.h"
#include "Entity/StaticEntity/Wall/Wall.h"
#include "Helper/Randomizer/Randomizer.h"
#include "Helper/TimeManager/TimeManager.h"

PMGame::Logic::Ghost::Ghost(const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
                            const PMGame::Logic::Coordinate2D::Coordinate& size, const float& power,
                            const float& stasisDuration)
    : AutomaticEntity(startPosition, size, 0.75f * power), fearDuration(10.0f / power), stasisDuration(stasisDuration),
      mode(Mode_Stasis), onModeChange(std::make_unique<GhostModeChangeEvent>(mode)),
      onEntityCollected(std::make_unique<EntityCollectedEvent>(50, false)) {
    SetIsKillable(false);
    SetMode(Mode_Stasis);
    PMGame::Logic::Helper::TimeManager::GetInstance().lock()->AddTimer(modeTimer);
}

void PMGame::Logic::Ghost::Accept(const std::weak_ptr<IEntityVisitor>& visitor) { visitor.lock()->Visit(*this); }

void PMGame::Logic::Ghost::CollideWith(const PacMan& pacMan) {
    if (WillCollide(pacMan)) {
        if (GetIsKillable()) {
            onEntityCollected->Notify(*onEntityCollected);
            Respawn();
        }
    }
}

void PMGame::Logic::Ghost::CollideWith(PMGame::Logic::Entity& entity) const { entity.CollideWith(*this); }

void PMGame::Logic::Ghost::CollideWith(const Wall& wall) {
    DynamicEntity::CollideWith(wall);
    if (WillCollide(wall))
        ChooseNextDirection();
}

void PMGame::Logic::Ghost::CollideWith(const Intersection& intersection) {
    const auto& intersectionIter =
        std::find(collidingWithIntersection.begin(), collidingWithIntersection.end(), intersection);
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate centeredCoord =
        PMGame::Logic::Coordinate2D::GetCenteredShrinked(intersection.GetPosition(), intersection.GetSize(), 10);
    if (PMGame::Logic::Coordinate2D::IsOverlapping(
            centeredCoord, {intersection.GetSize().GetX() / 10, intersection.GetSize().GetY() / 10}, GetNextPosition(),
            GetSize()) &&
        intersectionIter == collidingWithIntersection.end()) {
        collidingWithIntersection.push_back(intersection);
        ChooseNextDirection();
        DynamicEntity::CollideWith(intersection);
    } else if (!WillCollide(intersection) && intersectionIter != collidingWithIntersection.end())
        collidingWithIntersection.remove(intersection);
}

PMGame::Logic::GhostMode PMGame::Logic::Ghost::GetMode() const { return mode; }

void PMGame::Logic::Ghost::SetMode(const PMGame::Logic::GhostMode& newMode) {
    mode = newMode;
    switch (GetMode()) {
    case Mode_Fear: {
        SetIsKillable(true);
        SetSpeed(GetDefaultSpeed() / 1.5f);
        modeTimer = std::make_shared<PMGame::Logic::Helper::Timer>([&] { SetMode(Mode_Chase); }, fearDuration);
        PMGame::Logic::Helper::TimeManager::GetInstance().lock()->AddTimer(modeTimer);
        ChooseNextDirection();
        break;
    }
    case Mode_Stasis: {
        modeTimer = std::make_shared<PMGame::Logic::Helper::Timer>([&] { SetMode(Mode_Chase); }, stasisDuration);
        SetSpeed(GetDefaultSpeed());
        SetIsKillable(false);
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

PMGame::Logic::Coordinate2D::DiscreteDirection2D PMGame::Logic::Ghost::GetDirectionWithMinimumDistance() const {
    float minDistance{
        PMGame::Logic::Coordinate2D::GetManhattanDistance(GetNextPosition(*viableDirections.begin()), *target)};
    const auto random{PMGame::Logic::Helper::Randomizer::GetInstance()};

    std::vector<PMGame::Logic::Coordinate2D::DiscreteDirection2D> result;
    for (const auto& currentViableDirection : viableDirections) {
        const float currentDistance{
            PMGame::Logic::Coordinate2D::GetManhattanDistance(GetNextPosition(currentViableDirection), *target)};
        if (minDistance > currentDistance) {
            minDistance = currentDistance;
            result.clear();
            result.push_back(currentViableDirection);
        } else if (minDistance == currentDistance) {
            result.push_back(currentViableDirection);
        }
    }
    return result[random.lock()->GetRandomInteger(0, static_cast<int>(result.size() - 1))];
}

PMGame::Logic::Coordinate2D::DiscreteDirection2D PMGame::Logic::Ghost::GetDirectionWithMaximumDistance() const {
    float maxDistance{
        PMGame::Logic::Coordinate2D::GetManhattanDistance(GetNextPosition(*viableDirections.begin()), *target)};
    const auto random{PMGame::Logic::Helper::Randomizer::GetInstance()};

    std::vector<PMGame::Logic::Coordinate2D::DiscreteDirection2D> result;
    for (const auto& currentViableDirection : viableDirections) {
        const float currentDistance{
            PMGame::Logic::Coordinate2D::GetManhattanDistance(GetNextPosition(currentViableDirection), *target)};
        if (maxDistance < currentDistance) {
            maxDistance = currentDistance;
            result.clear();
            result.push_back(currentViableDirection);
        } else if (maxDistance == currentDistance) {
            result.push_back(currentViableDirection);
        }
    }
    return result[random.lock()->GetRandomInteger(0, static_cast<int>(result.size() - 1))];
}
void PMGame::Logic::Ghost::ChooseNextDirection() {
    if (!viableDirections.empty()) {
        const auto& random{PMGame::Logic::Helper::Randomizer::GetInstance()};
        const bool computeManhattanDistance{random.lock()->GetRandomFloat(0.0f, 1.0f) <= 0.5f};
        PMGame::Logic::Coordinate2D::DiscreteDirection2D bestDirection{};

        if (!target || !computeManhattanDistance || GetMode() == Mode_Stasis) {
            auto directionIter{viableDirections.begin()};
            const int advancer{random.lock()->GetRandomInteger(0, static_cast<int>(viableDirections.size() - 1))};
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
        SetNextDirection(bestDirection);
    }
}

void PMGame::Logic::Ghost::Update(const EntityPositionChangeEvent& eventData) {
    PMGame::Logic::Coordinate2D::NormalizedCoordinate position{eventData.newPosition};
    if (!target) {
        target = std::make_unique<PMGame::Logic::Coordinate2D::NormalizedCoordinate>(position);
    } else
        *target = position;
}

void PMGame::Logic::Ghost::Update(const EntityCollectedEvent& eventData) {
    if (eventData.collectedFruit) {
        SetMode(Mode_Fear);
    }
}

void PMGame::Logic::Ghost::Respawn() {
    SetMode(Mode_Chase);
    SetPosition(GetSpawn());
    ChooseNextDirection();
}
