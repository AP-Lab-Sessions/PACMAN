//

#ifndef PAC_MAN_ABSTRACTFACTORY_H
#define PAC_MAN_ABSTRACTFACTORY_H

#include "Coordinate/Coordinate.h"

#include <memory>

namespace PMGame::Logic {

class PacMan;
class Ghost;
class Wall;
class Fruit;
class Coin;

/**
 * @brief Factory interface for concrete entities.
 */
class AbstractFactory {
public:
    virtual std::unique_ptr<PacMan> CreatePacMan(const Coordinate2D::NormalizedCoordinate& startPosition,
                                                 const Coordinate2D::Coordinate& size) const = 0;

    virtual std::unique_ptr<Ghost> CreateGhost(const Coordinate2D::NormalizedCoordinate& startPosition,
                                               const Coordinate2D::Coordinate& size, const float& power,
                                               const float& stasisTime) const = 0;

    virtual std::unique_ptr<Wall> CreateWall(const Coordinate2D::NormalizedCoordinate& startPosition,
                                             const Coordinate2D::Coordinate& size) const = 0;

    virtual std::unique_ptr<Fruit> CreateFruit(const Coordinate2D::NormalizedCoordinate& startPosition,
                                               const Coordinate2D::Coordinate& size) const = 0;

    virtual std::unique_ptr<Coin> CreateCoin(const Coordinate2D::NormalizedCoordinate& startPosition,
                                             const Coordinate2D::Coordinate& size) const = 0;

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractFactory() = default;
};
} // namespace PMGame::Logic

#endif // PAC_MAN_ABSTRACTFACTORY_H
