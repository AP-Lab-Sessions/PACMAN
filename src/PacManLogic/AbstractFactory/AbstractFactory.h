//

#ifndef PAC_MAN_ABSTRACTFACTORY_H
#define PAC_MAN_ABSTRACTFACTORY_H

#include "PMLogic.h"
#include "Coordinate/Coordinate.h"
#include <memory>

class DynamicEntity;
class StaticEntity;
class CollectableEntity;
class AutomaticEntity;


class PMLogic::AbstractFactory {
public:
    virtual std::unique_ptr<DynamicEntity> CreatePacMan(
            const Coordinate2D::NormalizedCoordinate &startPosition
            ) const = 0;

    virtual std::unique_ptr<AutomaticEntity> CreateGhost(
            const Coordinate2D::NormalizedCoordinate &startPosition
            ) const = 0;

    virtual std::unique_ptr<StaticEntity> CreateWall(
            const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size
            ) const = 0;

    virtual std::unique_ptr<CollectableEntity> CreateFruit(
            const Coordinate2D::NormalizedCoordinate &startPosition
            ) const = 0;

    virtual std::unique_ptr<CollectableEntity> CreateCoin(
            const Coordinate2D::NormalizedCoordinate &startPosition
            ) const = 0;

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractFactory() = default;
};

#endif // PAC_MAN_ABSTRACTFACTORY_H
