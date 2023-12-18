//

#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H

#include "AbstractFactory/AbstractFactory.h"
#include "EntityView/EntityView.h"
#include <SFML/Graphics.hpp>
#include <vector>

class EntityFactory : public PMLogic::AbstractFactory {
protected:
    const std::weak_ptr<std::vector<std::function<void()>>> renderCallbacks;
    const std::weak_ptr<sf::RenderWindow> window;

    template<typename EntityType, typename EntityViewType>
    std::unique_ptr<EntityType> CreateEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                                             const Coordinate2D::Coordinate &size) const;

    template<typename DynamicEntityType, typename DynamicEntityViewType>
    std::unique_ptr<DynamicEntityType> CreateDynamicEntity(const Coordinate2D::NormalizedCoordinate &startPosition,
                                                           const Coordinate2D::Coordinate &size) const;
public:
    explicit EntityFactory(const std::weak_ptr<std::vector<std::function<void()>>> &observers_ptr,
                           const std::weak_ptr<sf::RenderWindow> &window);

    std::unique_ptr<PacMan> CreatePacMan(
            const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size
            ) const override;

    std::unique_ptr<Ghost> CreateGhost(
            const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size,
            const float &power) const override;

    std::unique_ptr<Wall> CreateWall(
            const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size
    ) const override;

    std::unique_ptr<Fruit> CreateFruit(
            const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size
            ) const override;

    std::unique_ptr<Coin> CreateCoin(
            const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size
            ) const override;
};

#endif // PACMAN_ENTITYFACTORY_H
