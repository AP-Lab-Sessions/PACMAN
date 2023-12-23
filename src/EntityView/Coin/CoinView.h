//

#ifndef PACMAN_COINVIEW_H
#define PACMAN_COINVIEW_H

#include "EntityView/EntityView.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"

/**
 * @brief View of the coin entity, listens to the event when the coin has been collected by pacman.
 */
class CoinView final : public EntityView, public PMLogic::IEventListener<EntityCollectedEvent>
{
protected:
    sf::RectangleShape coin;
public:
    explicit CoinView(const std::weak_ptr<sf::RenderWindow> &window);

    using EntityView::Update;

    /**
     * @brief makes the coin rectangleshape when the coin has been created.
     * @param eventData information about the coin entity
     */
    void Update(const EntityCreateEvent &eventData) final;

    /**
     * @brief Plays a sound when the coin has been collected
     * @param eventData
     */
    void Update(const EntityCollectedEvent &eventData) final;

    /**
     * @brief Renders the coin rectangleshape
     */
    void Render() const override;
};

#endif // PACMAN_COINVIEW_H
