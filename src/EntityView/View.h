//

#ifndef PACMAN_VIEW_H
#define PACMAN_VIEW_H

#include "Pattern/Observer/IObserver/IObserver.h"
#include "Game/SpriteSheet/SpriteSheet.h"
#include "PacManLogic/Helper/Camera/Camera.h"

class IEntityObserver : public PMLogic::IObserver {
public:
    virtual void Render() = 0;
};

template<typename EntityType>
class View : public IEntityObserver {
protected:
    const EntityType& entity;
    std::weak_ptr<sf::RenderWindow> window;

    sf::Sprite sprite;
    const SpriteSheet spriteSheet;

    sf::RectangleShape outline;
public:
    virtual void Load() = 0;
    void Render() override {
        window.lock()->draw(sprite);
        window.lock()->draw(outline);
    }
    View(const EntityType &entity, const std::weak_ptr<sf::RenderWindow> &window) : entity(entity), window(window),
    spriteSheet(SpriteSheet("assets/images/Sprites.png", 19,19, 14,14,0,3)){}
    ~View() override = default;
};

#endif // PACMAN_VIEW_H
