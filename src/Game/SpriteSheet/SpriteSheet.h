//

#ifndef PACMAN_SPRITESHEET_H
#define PACMAN_SPRITESHEET_H

#include "Coordinate/Coordinate.h"
#include <SFML/Graphics.hpp>
#include <memory>

/**
 * @brief A spritesheet 'helper' class that helps with obtaining a certain sprite from a given spritesheet.
 */
class SpriteSheet {
protected:
    /**
     * @brief The sprite sheet.
     */
    sf::Texture sheet;
    const unsigned int spritesPerRow, spritesPerColumn, horizontalPadding, verticalPadding, horizontalOffset,
        verticalOffset;

public:
    /**
     *
     * @param texturePath Path to the spritesheet texture
     * @param spritesPerRow Amount of sprites for each row (All rows should have the same amount)
     * @param spritesPerColumn Amount of sprites for each column (All columns should have the same amount)
     * @param horizontalPadding Horizontal intersprite padding (horizontal padding between each sprite)
     * @param verticalPadding  Vertical intersprite padding (verticaL padding between each sprite)
     * @param horizontalOffset Horizontal offset (when the sprites 'actually begin' horizontal-wise)
     * @param verticalOffset  Vertical offset (when the sprites 'actually begin' vertical-wise)
     */
    SpriteSheet(const std::string& texturePath, const unsigned int& spritesPerRow, const unsigned int& spritesPerColumn,
                const unsigned int& horizontalPadding = 0, const unsigned int& verticalPadding = 0,
                const unsigned int& horizontalOffset = 0, const unsigned int& verticalOffset = 0);

    /**
     * @brief Returns a sprite given the coordinates that is also correctly sized by looking at the projected size
     * @param x column
     * @param y row
     * @param projected the size that the sprite needs to be
     * @return the sprite
     */
    sf::Sprite GetSprite(const int& x, const int& y, const Coordinate2D::Coordinate& projected) const;

    /**
     * @brief Crops the spritesheet texture and positions it according to the given column and row, used by GetSprite()
     * @param column
     * @param row
     * @return cropped rectangle
     */
    sf::IntRect GetTextureRect(const int& column, const int& row) const;
};

#endif // PACMAN_SPRITESHEET_H
