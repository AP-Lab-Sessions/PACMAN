//

#include "FruitView.h"
#include "Helper/Randomizer/Randomizer.h"
#include "View/SoundManager/SoundManager.h"

PMGame::View::FruitView::FruitView(const std::weak_ptr<sf::RenderWindow>& window)
    : EntityView(window, 12, PMGame::Logic::Helper::Randomizer::GetInstance().lock()->GetRandomInteger(0, 6)) {}

void PMGame::View::FruitView::Update(const PMGame::Logic::EntityCollectedEvent&) {
    const auto& soundBuffer = SoundManager::GetInstance().lock();
    soundBuffer->Play("assets/audio/pacman_eatfruit.wav");
}