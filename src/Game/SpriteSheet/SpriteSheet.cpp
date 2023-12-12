//

#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const std::string &texturePath, const unsigned int &spritesPerRow,
                         const unsigned int &spritesPerColumn) : spritesPerRow(spritesPerRow),
                         spritesPerColumn(spritesPerColumn) {
    sheet.loadFromFile(texturePath);
}

sf::Sprite SpriteSheet::GetSprite(const int &column, const int &row, const Coordinate2D::Coordinate &projected) const {
    sf::Sprite result;
    const float spriteWidth {static_cast<float>(sheet.getSize().x)/static_cast<float>(spritesPerColumn)};
    const float spriteHeight {static_cast<float>(sheet.getSize().y)/static_cast<float>(spritesPerRow)};

    result.setTexture(sheet);
    result.setTextureRect(sf::IntRect(column*spriteWidth,row*spriteHeight,
                                      static_cast<int>(spriteWidth), static_cast<int>(spriteHeight)));
    result.setScale(spriteWidth/projected.GetX(),spriteHeight/projected.GetY());


    return result;
}