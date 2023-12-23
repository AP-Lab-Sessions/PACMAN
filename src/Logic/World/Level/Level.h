//

#ifndef PACMAN_LEVEL_H
#define PACMAN_LEVEL_H

#include "Events/EntityEvent/EntityCollectedEvent.h"
#include "Events/EntityEvent/EntityDestroyEvent.h"
#include "Pattern/AbstractFactory/AbstractFactory.h"
#include "Score/Score.h"
#include "UpdateVisitor/UpdateVisitor.h"

namespace PMGame::Logic {
/**
 * @brief A level that accordingly, creates entities, updates them and even destroys them.
 */
class Level : public IEventListener<EntityDestroyEvent>,
              public IEventListener<EntityCollectedEvent>,
              public std::enable_shared_from_this<Level> {
private:
    /**
     * @brief The entities that are to be destroyed
     */
    std::vector<std::weak_ptr<Entity>> destructables;

protected:
    /**
     * @brief String representing the level
     */
    const std::string levelStr;
    /**
     * @brief Size of the level string.
     */
    const std::pair<int, int> levelSize;

    /**
     * @brief Entity factory used for creating necessary entities.
     */
    const std::weak_ptr<AbstractFactory> factory;

    /**
     * @brief Entities that are currently existing in the level
     */
    std::list<std::shared_ptr<Entity>> entities;
    /**
     * @brief Player entity.
     */
    std::weak_ptr<PacMan> player;

    /**
     * @brief Current score.
     */
    std::weak_ptr<Score> score;
    /**
     * @brief Amount of lives the player currently has.
     */
    std::weak_ptr<int> lives;

    /**
     * @brief Visitor that updates the entities
     */
    std::shared_ptr<IEntityVisitor> updateVisitor;

    /**
     * @brief Difficulty number used for ghosts
     */
    float currentDifficulty;
    /**
     * @brief Amount of collectables currently existing in the level
     */
    int collectablesCount;

    /**
     * @brief Looping over all entities and calls collision (double dispatch) method on them
     */
    void DetectAllCollisions();
    /**
     * @brief Gets to next level and increases difficulty
     */
    void GoNextLevel();
    /**
     * @brief Detects all intersections in level string and adds them as entities to the actual level
     * @param intersectionSize Size of all intersections
     * @param startPosition Starting position
     */
    void AddIntersections(const Coordinate2D::Coordinate& intersectionSize,
                          Coordinate2D::NormalizedCoordinate startPosition);
    /**
     * @brief Gets all viable directions you can go from an intersection on position x,y of level string
     * @param x column of level string
     * @param y row of level string
     * @return All viable directions you can go from the intersection.
     */
    std::list<Coordinate2D::DiscreteDirection2D> GetIntersectionDirections(const int& x, const int& y) const;
    /**
     * @brief Gets the symbol from the level string given x,y position. This is done modulo-wise so x,y cannot get out
     * of bounds.
     * @param x column of level string
     * @param y row of level string
     * @return The symbol.
     */
    char GetLevelChar(const int& x, const int& y) const;
    /**
     * @brief Tells if the symbol is not a wall or a newline.
     * @param c the symbol.
     * @return Boolean denoting if the symbol is not a wall or a newline.
     */
    bool CharIsPath(const char& c) const;

public:
    /**
     *
     * @param levelPath Path to the level text file
     * @param factory Entity factory
     * @param score Current score
     * @param lives Current number of lives
     */
    Level(const std::string& levelPath, const std::weak_ptr<AbstractFactory>& factory,
          const std::weak_ptr<Score>& score, const std::weak_ptr<int>& lives);

    /**
     * @brief Gets the pacman entity which acts as the playable entity.
     * @return The PacMan entity.
     */
    std::weak_ptr<PacMan> GetPlayer() const;

    /**
     * @brief Updates the entities accordingly.
     */
    void Update();

    /**
     * @brief Called when an entity gets destroyed, the entity gets added to the destructables and gets deleted from the
     * entities next update
     * @param entityDestroy
     */
    void Update(const EntityDestroyEvent& entityDestroy) override;

    /**
     * @brief Called when an entity gets collected, collectablesAmount is consequently decremented.
     * @param entityCollected
     */
    void Update(const EntityCollectedEvent& entityCollected) override;

    /**
     * @brief Loads the level by reading the level string and creating all the necessary entities.
     */
    void Load();

    /**
     * @brief Restarts the level by respawning all entities to their starting positions.
     */
    void Restart();
};
} // namespace PMGame::Logic
#endif // PACMAN_LEVEL_H
