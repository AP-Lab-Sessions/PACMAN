//

#include "PacManView.h"
#include "View/SoundManager/SoundManager.h"

PMGame::View::PacManView::PacManView(const std::weak_ptr<sf::RenderWindow>& window)
    : DynamicEntityView(window, 17, 0, 3) {}

void PMGame::View::PacManView::Update(const PMGame::Logic::EntityCreateEvent& event) {
    EntityView::Update(event);
    const auto& soundBuffer = SoundManager::GetInstance().lock();
    soundBuffer->Play("assets/audio/pacman_beginning.wav");
}