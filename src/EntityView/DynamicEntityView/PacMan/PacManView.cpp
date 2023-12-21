//

#include "PacManView.h"
#include "Game/SoundManager/SoundManager.h"

PacManView::PacManView(const std::weak_ptr<sf::RenderWindow> &window)
: DynamicEntityView(window, 17,0,3) {
}

void PacManView::Update(const EntityCreateEvent& event) {
    EntityView::Update(event);
    const auto &soundBuffer = SoundManager::GetInstance().lock();
    soundBuffer->Play("assets/audio/pacman_beginning.wav");
}