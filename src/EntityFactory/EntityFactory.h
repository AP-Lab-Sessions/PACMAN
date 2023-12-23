//

#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H

#include "Pattern/AbstractFactory/AbstractFactory.h"
#include "View/EntityView/EntityView.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace PMGame {
/**
 * @brief concrete factory which produces the necessary entities and corresponding views
 */
class EntityFactory : public Logic::AbstractFactory {
protected:
    std::vector<std::shared_ptr<View::EntityView>>& viewsRef;
    const std::weak_ptr<sf::RenderWindow> window;

public:
    /**
     * @brief constructor of the factory
     * @param viewsRef reference to the views of the game so whenever a view gets added it's added into the game
     * @param window the render window of the game
     */
    explicit EntityFactory(std::vector<std::shared_ptr<View::EntityView>>& viewsRef,
                           const std::weak_ptr<sf::RenderWindow>& window);

    std::unique_ptr<PMGame::Logic::PacMan> CreatePacMan(
        const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
        const PMGame::Logic::Coordinate2D::Coordinate& size) const override;

    std::unique_ptr<PMGame::Logic::Ghost> CreateGhost(
        const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
        const PMGame::Logic::Coordinate2D::Coordinate& size, const float& power,
        const float& stasisTime) const override;

    std::unique_ptr<PMGame::Logic::Wall> CreateWall(
        const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
        const PMGame::Logic::Coordinate2D::Coordinate& size) const override;

    std::unique_ptr<PMGame::Logic::Fruit> CreateFruit(
        const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
        const PMGame::Logic::Coordinate2D::Coordinate& size) const override;

    std::unique_ptr<PMGame::Logic::Coin> CreateCoin(
        const PMGame::Logic::Coordinate2D::NormalizedCoordinate& startPosition,
        const PMGame::Logic::Coordinate2D::Coordinate& size) const override;
};
} // namespace PMGame

#endif // PACMAN_ENTITYFACTORY_H
