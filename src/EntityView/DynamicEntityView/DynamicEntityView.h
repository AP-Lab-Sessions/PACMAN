//

#ifndef PACMAN_DYNAMICENTITYVIEW_H
#define PACMAN_DYNAMICENTITYVIEW_H

#include "EntityView/EntityView.h"
#include "Events/EntityEvent/EntityDirectionChangeEvent.h"
#include "Events/EntityEvent/EntityPositionChangeEvent.h"

class DynamicEntityView : public EntityView,
                          public PMLogic::IEventListener<EntityPositionChangeEvent>,
                          public PMLogic::IEventListener<EntityDirectionChangeEvent>{
private:
    std::shared_ptr<PMLogic::Helper::Timer> animateTimer;
protected:
    const int spritesPerAnim;
    int currentAnim;
    int currentDirection;

    void Animate();
    void UpdateSprite();
public:
    DynamicEntityView(const std::weak_ptr<sf::RenderWindow> &window,
                      const int &spriteColumn, const int &spriteRow,
                      const int &spritesPerAnim=1);
    ~DynamicEntityView() override = default;

    using PMLogic::IEventListener<EntityCreateEvent>::Update;
    using PMLogic::IEventListener<EntityDestroyEvent>::Update;

    void Update(const EntityPositionChangeEvent &eventData) override;

    void Update(const EntityDirectionChangeEvent &eventData) override;
};

#endif // PACMAN_DYNAMICENTITYVIEW_H
