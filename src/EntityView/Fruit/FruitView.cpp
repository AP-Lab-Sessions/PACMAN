//

#include "FruitView.h"
#include "Game/SoundManager/SoundManager.h"
#include "Helper/Random/Random.h"

FruitView::FruitView(const std::weak_ptr<sf::RenderWindow> &window)
    : EntityView(window,12,PMLogic::Helper::Random::GetInstance().lock()->GetRandomInteger(0,6)) {}

void FruitView::Update(const EntityCollectedEvent&) {
    const auto &soundBuffer = SoundManager::GetInstance().lock();
    soundBuffer->Play("assets/audio/pacman_eatfruit.wav");
}