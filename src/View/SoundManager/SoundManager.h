//

#ifndef PACMAN_SOUNDMANAGER_H
#define PACMAN_SOUNDMANAGER_H

#include "Logic/Pattern/Singleton/Singleton.h"

#include <SFML/Audio.hpp>
#include <unordered_map>
namespace PMGame::View {
/**
 * @brief A singleton that plays and manages sounds
 */
class SoundManager : public PMGame::Logic::Singleton<SoundManager> {
protected:
    /**
     * @brief Wraps a sound and a buffer together so they can be used together.
     */
    class SoundPlayer {
    public:
        sf::SoundBuffer buffer;
        sf::Sound sound;

        SoundPlayer() : buffer(sf::SoundBuffer()), sound(sf::Sound(buffer)) {}
    };

    std::unordered_map<std::string, SoundPlayer> soundPlayers;

public:
    /**
     * @brief Plays a sound on a separate buffer given the path of a sound file.
     * @param soundPath The path to the sound file.
     */
    void Play(const std::string& soundPath);
};
} // namespace PMGame::View
#endif // PACMAN_SOUNDMANAGER_H