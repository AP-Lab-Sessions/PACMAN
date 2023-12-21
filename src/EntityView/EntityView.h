//

#ifndef PACMAN_ENTITYVIEW_H
#define PACMAN_ENTITYVIEW_H

#include "Pattern/Observer/EventListener/IEventListener.h"

#include "Events/EntityEvent/EntityDestroyEvent.h"
#include "Events/EntityEvent/EntityCreateEvent.h"

#include "Game/SpriteSheet/SpriteSheet.h"
#include "PacManLogic/Helper/Camera/Camera.h"

class EntityView : public PMLogic::IEventListener<EntityCreateEvent>,
                   public PMLogic::IEventListener<EntityDestroyEvent> {
protected:
    std::weak_ptr<sf::RenderWindow> window;

    sf::Sprite sprite;
    const SpriteSheet spriteSheet;

    bool entityDestroyed;

    const int baseSpriteColumn, baseSpriteRow;
    int spriteColumn, spriteRow;
public:
    virtual void Render() const;

    explicit EntityView(const std::weak_ptr<sf::RenderWindow> &window,
                        const int &spriteColumn=0, const int &spriteRow=0);
    ~EntityView() override = default;

    void Update(const EntityCreateEvent &eventData) override;

    void Update(const EntityDestroyEvent &event) override;
};

#endif // PACMAN_ENTITYVIEW_H
