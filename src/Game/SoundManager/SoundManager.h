//

#ifndef PACMAN_SOUNDMANAGER_H
#define PACMAN_SOUNDMANAGER_H

#include "PacManLogic/Pattern/Singleton/Singleton.h"

#include <SFML/Audio.hpp>

#include <unordered_map>

class SoundManager : public PMLogic::Singleton<SoundManager> {
protected:
    class SoundPlayer {
    public:
        sf::SoundBuffer buffer;
        sf::Sound sound;

        SoundPlayer() : buffer(sf::SoundBuffer()), sound(sf::Sound(buffer)) {}
    };

    std::unordered_map<std::string, SoundPlayer> soundPlayers;
public:
    void Play(const std::string &soundPath);
};

#endif // PACMAN_SOUNDMANAGER_H
