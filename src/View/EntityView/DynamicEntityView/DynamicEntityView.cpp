//
#include "DynamicEntityView.h"
#include "Helper/TimeManager/TimeManager.h"

PMGame::View::DynamicEntityView::DynamicEntityView(const std::weak_ptr<sf::RenderWindow>& window,
                                                   const int& spriteColumn, const int& spriteRow,
                                                   const int& spritesPerAnim)
    : EntityView(window, spriteColumn, spriteRow), spritesPerAnim(spritesPerAnim), currentAnim(spritesPerAnim - 1),
      currentDirection(0) {
    Animate();
}

void PMGame::View::DynamicEntityView::Animate() {
    UpdateSprite();
    currentAnim = (!currentAnim) ? spritesPerAnim - 1 : currentAnim - 1;

    const std::function<void()> callback = [&] { Animate(); };
    animateTimer = std::make_shared<PMGame::Logic::Helper::Timer>(callback, 0.15f);
    PMGame::Logic::Helper::TimeManager::GetInstance().lock()->AddTimer(animateTimer);
}

void PMGame::View::DynamicEntityView::Update(const PMGame::Logic::EntityPositionChangeEvent& eventData) {
    const sf::Vector2f size = window.lock()->getDefaultView().getSize();

    PMGame::Logic::Helper::Camera camera(static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y));

    const auto& coords = camera.Project(eventData.newPosition);

    sprite.setPosition(coords.GetX(), coords.GetY());
}
void PMGame::View::DynamicEntityView::UpdateSprite() {
    sprite.setTextureRect(
        spriteSheet.GetTextureRect(spriteColumn, (spriteRow + currentDirection * spritesPerAnim) + currentAnim));
}
void PMGame::View::DynamicEntityView::Update(const PMGame::Logic::EntityDirectionChangeEvent& eventData) {
    const std::array<PMGame::Logic::Coordinate2D::DiscreteDirection2D, 4> directions = {
        PMGame::Logic::Coordinate2D::Direction_Right, PMGame::Logic::Coordinate2D::Direction_Down,
        PMGame::Logic::Coordinate2D::Direction_Left, PMGame::Logic::Coordinate2D::Direction_Up};

    int factor = 0;
    for (; eventData.newDirection != directions[factor]; factor++)
        ;

    currentDirection = factor;
    UpdateSprite();
}
