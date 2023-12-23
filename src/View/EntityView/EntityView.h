//

#ifndef PACMAN_ENTITYVIEW_H
#define PACMAN_ENTITYVIEW_H

#include "Pattern/Observer/EventListener/IEventListener.h"

#include "Events/EntityEvent/EntityCreateEvent.h"
#include "Events/EntityEvent/EntityDestroyEvent.h"

#include "Logic/Helper/Camera/Camera.h"
#include "View/SpriteSheet/SpriteSheet.h"

namespace PMGame::View {
/**
 * @brief View of an entity, listens to the creation and destruction of the entity
 */
class EntityView : public PMGame::Logic::IEventListener<PMGame::Logic::EntityCreateEvent>,
                   public PMGame::Logic::IEventListener<PMGame::Logic::EntityDestroyEvent> {
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
    explicit EntityView(const std::weak_ptr<sf::RenderWindow>& window, const int& spriteColumn = 0,
                        const int& spriteRow = 0);
    ~EntityView() override = default;

    /**
     * @brief Does something whenever the entity gets created.
     * @param eventData
     */
    void Update(const PMGame::Logic::EntityCreateEvent& eventData) override;

    /**
     * @brief Does something wheneer the entity gets destroyed
     * @param event
     */
    void Update(const PMGame::Logic::EntityDestroyEvent& event) override;
};
} // namespace PMGame::View

#endif // PACMAN_ENTITYVIEW_H
