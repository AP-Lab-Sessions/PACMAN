//

#ifndef PACMAN_SPRITESHEET_H
#define PACMAN_SPRITESHEET_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "Coordinate/Coordinate.h"

class SpriteSheet {
protected:
    sf::Texture sheet;
    const unsigned int spritesPerRow, spritesPerColumn,
        horizontalPadding, verticalPadding,
        horizontalOffset, verticalOffset;
public:
    SpriteSheet(const std::string &texturePath,
                const unsigned int &spritesPerRow, const unsigned int &spritesPerColumn,
                const unsigned int &horizontalPadding=0, const unsigned int &verticalPadding=0,
                const unsigned int &horizontalOffset=0, const unsigned int &verticalOffset=0);
    sf::Sprite GetSprite(const  int &x, const int &y, const Coordinate2D::Coordinate &projected) const;

    sf::IntRect GetTextureRect(const int &column, const int &row) const;
};


#endif //PACMAN_SPRITESHEET_H
