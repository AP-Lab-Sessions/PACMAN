//

#ifndef PACMAN_ENTITYVIEW_H
#define PACMAN_ENTITYVIEW_H

#include "Pattern/Observer/EventListener/IEventListener.h"

#include "Events/EntityEvent/EntityDestroyEvent.h"
#include "Events/EntityEvent/EntityCreateEvent.h"

#include "Game/SpriteSheet/SpriteSheet.h"
#include "PacManLogic/Helper/Camera/Camera.h"


/**
 * @brief View of an entity, listens to the creation and destruction of the entity
 */
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
    /**
     * @brief Renders the entity
     */
    virtual void Render() const;

    /**
     * @brief The constructor of the view.
     * @param window the render window of the game
     * @param spriteColumn the column of the spritesheet
     * @param spriteRow the row of the spritesheet
     */
    explicit EntityView(const std::weak_ptr<sf::RenderWindow> &window,
                        const int &spriteColumn=0, const int &spriteRow=0);
    ~EntityView() override = default;

    /**
     * @brief Does something whenever the entity gets created.
     * @param eventData
     */
    void Update(const EntityCreateEvent &eventData) override;

    /**
     * @brief Does something wheneer the entity gets destroyed
     * @param event
     */
    void Update(const EntityDestroyEvent &event) override;
};

#endif // PACMAN_ENTITYVIEW_H
