//

#ifndef PACMAN_ASSETS_H
#define PACMAN_ASSETS_H

#include <SFML/Graphics.hpp>
#include <memory>

class Assets {
    sf::Font mainFont;

    static std::shared_ptr<Assets> instance;
    Assets();
public:
    Assets(Assets &) = delete;
    void operator=(const Assets &) = delete;

    static std::weak_ptr<Assets> GetInstance();

    sf::Font GetMainFont() const;
};

#endif // PACMAN_ASSETS_H
