//

#include "SpriteSheet.h"
#include <cmath>

SpriteSheet::SpriteSheet(const std::string &texturePath, const unsigned int &spritesPerRow,
                         const unsigned int &spritesPerColumn,
                         const unsigned int &horizontalPadding, const unsigned int &verticalPadding,
                         const unsigned int &horizontalOffset, const unsigned int &verticalOffset) :
                         spritesPerRow(spritesPerRow), spritesPerColumn(spritesPerColumn),
                         horizontalPadding(horizontalPadding), verticalPadding(verticalPadding),
                         horizontalOffset(horizontalOffset), verticalOffset(verticalOffset)
                        {
    sheet.loadFromFile(texturePath);
}
sf::IntRect SpriteSheet::GetTextureRect(const int& column, const int& row) const {
    const float spriteWidth =
        static_cast<float>(sheet.getSize().x)/static_cast<float>(spritesPerColumn)-static_cast<float>(horizontalPadding);

    const float spriteHeight =
        static_cast<float>(sheet.getSize().y)/static_cast<float>(spritesPerRow)-static_cast<float>(verticalPadding);

    sf::IntRect result = sf::IntRect(column*(std::ceil(spriteWidth)+horizontalPadding)+horizontalOffset,
                       row*(std::ceil(spriteHeight)+verticalPadding)+verticalOffset,
                       std::ceil(spriteWidth),
                       std::ceil(spriteHeight));
    return result;
}
sf::Sprite SpriteSheet::GetSprite(const int &column, const int &row, const Coordinate2D::Coordinate &projected) const {
    sf::Sprite result;
    const float spriteWidth =
            static_cast<float>(sheet.getSize().x)/static_cast<float>(spritesPerColumn)-static_cast<float>(horizontalPadding);

    const float spriteHeight =
            static_cast<float>(sheet.getSize().y)/static_cast<float>(spritesPerRow)-static_cast<float>(verticalPadding);

    result.setTexture(sheet);
    result.setTextureRect(GetTextureRect(column, row));

    result.setScale(projected.GetX()/std::ceil(spriteWidth),projected.GetY()/std::ceil(spriteHeight));

    return result;
}