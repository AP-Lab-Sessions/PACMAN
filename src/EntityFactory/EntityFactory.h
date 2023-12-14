//

#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H

#include "AbstractFactory/AbstractFactory.h"
#include "EntityView/View.h"
#include <vector>
#include <SFML/Graphics.hpp>

class EntityFactory : public PMLogic::AbstractFactory {
protected:
    const std::weak_ptr<std::vector<std::function<void()>>> renderCallbacks;
    const std::weak_ptr<sf::RenderWindow> window;

    template<typename EntityType, typename EntityViewType>
    std::unique_ptr<EntityType> CreateEntity(const Coordinate2D::NormalizedCoordinate &startPosition) const;
public:
    explicit EntityFactory(const std::weak_ptr<std::vector<std::function<void()>>> &observers_ptr,
                           const std::weak_ptr<sf::RenderWindow> &window);

    std::unique_ptr<DynamicEntity> CreatePacMan(
            const Coordinate2D::NormalizedCoordinate &startPosition
            ) const override;

    std::unique_ptr<DynamicEntity> CreateGhost(
            const Coordinate2D::NormalizedCoordinate &startPosition
            ) const override;

    std::unique_ptr<StaticEntity> CreateWall(
            const Coordinate2D::NormalizedCoordinate &startPosition, const Coordinate2D::Coordinate &size
    ) const override;

    std::unique_ptr<CollectableEntity> CreateFruit(
            const Coordinate2D::NormalizedCoordinate &startPosition
            ) const override;

    std::unique_ptr<CollectableEntity> CreateCoin(
            const Coordinate2D::NormalizedCoordinate &startPosition
            ) const override;
};

#endif // PACMAN_ENTITYFACTORY_H
