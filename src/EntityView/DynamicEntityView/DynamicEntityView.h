//

#ifndef PACMAN_DYNAMICENTITYVIEW_H
#define PACMAN_DYNAMICENTITYVIEW_H

#include "EntityView/EntityView.h"
#include "Events/EntityEvent/EntityDirectionChangeEvent.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"

/**
 * @brief View of a dynamic entity, it listens to the entity's position and direction change
 */
class DynamicEntityView : public EntityView,
                          public PMLogic::IEventListener<EntityPositionChangeEvent>,
                          public PMLogic::IEventListener<EntityDirectionChangeEvent> {
private:
    std::shared_ptr<PMLogic::Helper::Timer> animateTimer;

protected:
    const int spritesPerAnim;
    int currentAnim;
    int currentDirection;

    /**
     * @brief Animates the view by changing the current animation every interval using the timer helper class
     */
    void Animate();
    /**
     * @brief Uses all information about the current state of the entity and the view and updates the sprite
     */
    void UpdateSprite();

public:
    /**
     *
     * @param window render window of the game.
     * @param spriteColumn column in the spritesheet
     * @param spriteRow row in the spritesheet
     * @param spritesPerAnim amount of sprites used in one animation
     */
    DynamicEntityView(const std::weak_ptr<sf::RenderWindow>& window, const int& spriteColumn, const int& spriteRow,
                      const int& spritesPerAnim = 1);
    ~DynamicEntityView() override = default;

    using PMLogic::IEventListener<EntityCreateEvent>::Update;
    using PMLogic::IEventListener<EntityDestroyEvent>::Update;

    /**
     * @brief Gets called when the position of the entity changes, the view then changes the position of the sprite
     * accordingly
     * @param eventData information about the next position
     */
    void Update(const EntityPositionChangeEvent& eventData) override;

    /**
     * @brief Gets called when the direction of the entity changes, the view then changes the sprite accordingly
     * @param eventData information about the next direction
     */
    void Update(const EntityDirectionChangeEvent& eventData) override;
};

#endif // PACMAN_DYNAMICENTITYVIEW_H
