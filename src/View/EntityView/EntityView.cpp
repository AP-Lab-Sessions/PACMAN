//
#include "EntityView.h"

PMGame::View::EntityView::EntityView(const std::weak_ptr<sf::RenderWindow>& window, const int& spriteColumn,
                                     const int& spriteRow)
    : window(window), spriteSheet(SpriteSheet("assets/images/Sprites.png", 19, 19, 14, 14, 0, 3)),
      entityDestroyed(false), baseSpriteColumn(spriteColumn), baseSpriteRow(spriteRow), spriteColumn(spriteColumn),
      spriteRow(spriteRow) {}

void PMGame::View::EntityView::Update(const PMGame::Logic::EntityCreateEvent& eventData) {
    entityDestroyed = false;
    const sf::Vector2f size = window.lock()->getDefaultView().getSize();

    PMGame::Logic::Helper::Camera camera(static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y));
    const auto& pos = camera.Project(eventData.position);

    sprite = spriteSheet.GetSprite(spriteColumn, spriteRow, camera.ProjectSize(eventData.size));
    sprite.setPosition(pos.GetX(), pos.GetY());
}
void PMGame::View::EntityView::Update(const PMGame::Logic::EntityDestroyEvent&) { entityDestroyed = true; }

void PMGame::View::EntityView::Render() const {
    if (!entityDestroyed) {
        window.lock()->draw(sprite);
    }
}