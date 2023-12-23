//

#include "SoundManager.h"

#include <iostream>

void SoundManager::Play(const std::string& soundPath) {
    if (soundPlayers.find(soundPath) == soundPlayers.end())
        soundPlayers[soundPath] = SoundPlayer();

    SoundPlayer& soundPlayer = soundPlayers[soundPath];

    if (soundPlayer.sound.getStatus() == sf::Sound::Status::Stopped) {
        soundPlayer.sound = sf::Sound(soundPlayer.buffer);
        if (soundPlayer.buffer.loadFromFile(soundPath))
            soundPlayer.sound.play();
        else
            std::cerr << "Cannot play sound " << soundPath << std::endl;
    }
}
