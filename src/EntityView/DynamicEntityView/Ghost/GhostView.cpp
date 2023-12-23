//

#include "GhostView.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Game/SoundManager/SoundManager.h"
#include "PacManLogic/Helper/Random/Random.h"

GhostView::GhostView(const std::weak_ptr<sf::RenderWindow>& window)
    : DynamicEntityView(window, PMLogic::Helper::Random::GetInstance().lock()->GetRandomInteger(0, 5), 0, 2) {}

void GhostView::Update(const GhostModeChangeEvent& eventData) {
    switch (eventData.newMode) {
    case Mode_Fear:
        spriteRow = 11;
        spriteColumn = 0;
        break;
    default:
        spriteRow = baseSpriteRow;
        spriteColumn = baseSpriteColumn;
        break;
    }
    UpdateSprite();
}

void GhostView::Update(const EntityCollectedEvent&) {
    const auto& soundBuffer = SoundManager::GetInstance().lock();
    soundBuffer->Play("assets/audio/pacman_eatghost.wav");
}