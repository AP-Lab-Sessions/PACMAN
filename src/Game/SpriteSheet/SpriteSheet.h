//

#ifndef PACMAN_SPRITESHEET_H
#define PACMAN_SPRITESHEET_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "Coordinate/Coordinate.h"

class SpriteSheet {
protected:
    sf::Texture sheet;
    const unsigned int spritesPerRow, spritesPerColumn;
public:
    SpriteSheet(const std::string &texturePath,
                const unsigned int &spritesPerRow, const unsigned int &spritesPerColumn);

    sf::Sprite GetSprite(const  int &x, const int &y, const Coordinate2D::Coordinate &projected) const;
};


#endif //PACMAN_SPRITESHEET_H
