//

#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H

#include "Pattern/AbstractFactory/AbstractFactory.h"
#include "EntityView/EntityView.h"
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief concrete factory which produces the necessary entities and corresponding views
 */
class EntityFactory : public PMLogic::AbstractFactory {
protected:
    std::vector<std::shared_ptr<EntityView>> &viewsRef;
    const std::weak_ptr<sf::RenderWindow> window;

public:
    /**
     * @brief constructor of the factory
     * @param viewsRef reference to the views of the game so whenever a view gets added it's added into the game
     * @param window the render window of the game
     */
    explicit EntityFactory( std::vector<std::shared_ptr<EntityView>> &viewsRef,
                           const std::weak_ptr<sf::RenderWindow> &window);

    std::unique_ptr<PacMan> CreatePacMan(
            const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size
            ) const override;

    std::unique_ptr<Ghost> CreateGhost(
            const Coordinate2D::NormalizedCoordinate &startPosition,  const Coordinate2D::Coordinate &size,
            const float &power, const float &stasisTime) const override;

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
