//

#include "GhostView.h"
#include "Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.h"
#include "Logic/Helper/Randomizer/Randomizer.h"
#include "View/SoundManager/SoundManager.h"

PMGame::View::GhostView::GhostView(const std::weak_ptr<sf::RenderWindow>& window)
    : DynamicEntityView(window, PMGame::Logic::Helper::Randomizer::GetInstance().lock()->GetRandomInteger(0, 5), 0, 2) {
}

void PMGame::View::GhostView::Update(const PMGame::Logic::GhostModeChangeEvent& eventData) {
    switch (eventData.newMode) {
    case PMGame::Logic::Mode_Fear:
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

void PMGame::View::GhostView::Update(const PMGame::Logic::EntityCollectedEvent&) {
    const auto& soundBuffer = SoundManager::GetInstance().lock();
    soundBuffer->Play("assets/audio/pacman_eatghost.wav");
}