//

#ifndef PACMAN_LEVEL_H
#define PACMAN_LEVEL_H

#include "UpdateVisitor/UpdateVisitor.h"
#include "Pattern/AbstractFactory/AbstractFactory.h"
#include "Score/Score.h"
#include "Events/EntityEvent/EntityDestroyEvent.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"


class Level : public PMLogic::IEventListener<EntityDestroyEvent>,
              public PMLogic::IEventListener<EntityCollectedEvent>,
              public std::enable_shared_from_this<Level>{
private:
    std::vector<std::weak_ptr<PMLogic::Entity>> destructables;
protected:
    const std::string levelStr;
    const std::pair<int, int> levelSize;

    const std::weak_ptr<PMLogic::AbstractFactory> factory;

    std::list<std::shared_ptr<PMLogic::Entity>> entities;
    std::weak_ptr<PacMan> player;

    std::weak_ptr<PMLogic::Score> score;
    std::weak_ptr<int> lives;

    std::shared_ptr<IEntityVisitor> updateVisitor;

    float currentDifficulty;
    int collectablesCount;

    void DetectAllCollisions();
    void Reload();
    void AddIntersections(const Coordinate2D::Coordinate &intersectionSize,
                          Coordinate2D::NormalizedCoordinate startPosition);
    std::list<Coordinate2D::DiscreteDirection2D> GetIntersectionDirections(const int &x, const int &y) const;
    char GetLevelChar(const int &x, const int &y) const;
    bool CharIsPath(const char &c) const;

public:


    Level(const std::string &levelPath,
          const std::weak_ptr<PMLogic::AbstractFactory> &factory,
          const std::weak_ptr<PMLogic::Score> &score, const std::weak_ptr<int> &lives);

    std::weak_ptr<PacMan> GetPlayer() const;

    void Update();

    void Update(const EntityDestroyEvent &entityDestroy) override;

    void Update(const EntityCollectedEvent &entityCollected) override;

    void Load();

    void Restart();
};

#endif // PACMAN_LEVEL_H
