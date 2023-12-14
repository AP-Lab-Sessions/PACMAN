//

#ifndef PACMAN_VIEW_H
#define PACMAN_VIEW_H

#include "Pattern/Observer/EventListener/IEventListener.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"
#include "Events/EntityEvent/EntityDestroyEvent.h"
#include "Game/SpriteSheet/SpriteSheet.h"
#include "PacManLogic/Helper/Camera/Camera.h"

#include <iostream>

template<typename EntityType>
class View : public PMLogic::IEventListener<EntityPositionChangeEvent>,
        public PMLogic::IEventListener<EntityDestroyEvent> {
protected:
    const EntityType& entity;
    std::weak_ptr<sf::RenderWindow> window;

    sf::Sprite sprite;
    const SpriteSheet spriteSheet;

    bool entityDestroyed;
public:
    virtual void Load() = 0;
    virtual void Render() {
        if(!entityDestroyed) {
            window.lock()->draw(sprite);
        }
    }

    View(const EntityType &entity, const std::weak_ptr<sf::RenderWindow> &window) : entity(entity), window(window),
    spriteSheet(SpriteSheet("assets/images/Sprites.png", 19,19, 14,14,0,3)), entityDestroyed(false) {}
    ~View() override = default;

    void Update(const EntityPositionChangeEvent &eventData) override {
        const sf::Vector2f size = window.lock()->getDefaultView().getSize();

        PMLogic::Helper::Camera camera(
                static_cast<unsigned int>(size.x),
                static_cast<unsigned int>(size.y));

        const auto &coords = camera.Project(eventData.newPosition);

        sprite.setPosition(coords.GetX(), coords.GetY());
    }
    void Update(const EntityDestroyEvent &event) override {
        entityDestroyed = true;
    }
};

#endif // PACMAN_VIEW_H
