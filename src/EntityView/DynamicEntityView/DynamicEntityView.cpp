//
#include "DynamicEntityView.h"
#include "Helper/TimeManager/TimeManager.h"

DynamicEntityView::DynamicEntityView(const std::weak_ptr<sf::RenderWindow>& window, const int& spriteColumn,
                                     const int& spriteRow, const int& spritesPerAnim)
    : EntityView(window, spriteColumn, spriteRow), spritesPerAnim(spritesPerAnim), currentAnim(spritesPerAnim - 1),
      currentDirection(0) {
    Animate();
}

void DynamicEntityView::Animate() {
    UpdateSprite();
    currentAnim = (!currentAnim) ? spritesPerAnim - 1 : currentAnim - 1;

    const std::function<void()> callback = [&] { Animate(); };
    animateTimer = std::make_shared<PMLogic::Helper::Timer>(callback, 0.15f);
    PMLogic::Helper::TimeManager::GetInstance().lock()->AddTimer(animateTimer);
}

void DynamicEntityView::Update(const EntityPositionChangeEvent& eventData) {
    const sf::Vector2f size = window.lock()->getDefaultView().getSize();

    PMLogic::Helper::Camera camera(static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y));

    const auto& coords = camera.Project(eventData.newPosition);

    sprite.setPosition(coords.GetX(), coords.GetY());
}
void DynamicEntityView::UpdateSprite() {
    sprite.setTextureRect(
        spriteSheet.GetTextureRect(spriteColumn, (spriteRow + currentDirection * spritesPerAnim) + currentAnim));
}
void DynamicEntityView::Update(const EntityDirectionChangeEvent& eventData) {
    const std::array<Coordinate2D::DiscreteDirection2D, 4> directions = {
        Coordinate2D::Direction_Right, Coordinate2D::Direction_Down, Coordinate2D::Direction_Left,
        Coordinate2D::Direction_Up};

    int factor = 0;
    for (; eventData.newDirection != directions[factor]; factor++)
        ;

    currentDirection = factor;
    UpdateSprite();
}
