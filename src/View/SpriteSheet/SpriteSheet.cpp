//

#include "SpriteSheet.h"
#include <cmath>

PMGame::View::SpriteSheet::SpriteSheet(const std::string& texturePath, const int& spritesPerRow,
                                       const int& spritesPerColumn, const int& horizontalPadding,
                                       const int& verticalPadding, const int& horizontalOffset,
                                       const int& verticalOffset)
    : spritesPerRow(spritesPerRow), spritesPerColumn(spritesPerColumn), horizontalPadding(horizontalPadding),
      verticalPadding(verticalPadding), horizontalOffset(horizontalOffset), verticalOffset(verticalOffset) {
    sheet.loadFromFile(texturePath);
}
sf::IntRect PMGame::View::SpriteSheet::GetTextureRect(const int& column, const int& row) const {
    const float spriteWidth =
        sf::Vector2f(sheet.getSize()).x / static_cast<float>(spritesPerColumn) - static_cast<float>(horizontalPadding);

    const float spriteHeight =
        sf::Vector2f(sheet.getSize()).y / static_cast<float>(spritesPerRow) - static_cast<float>(verticalPadding);

    sf::IntRect result =
        sf::IntRect(column * (static_cast<int>(std::ceil(spriteWidth)) + horizontalPadding) + horizontalOffset,
                    row * (static_cast<int>(std::ceil(spriteHeight)) + verticalPadding) + verticalOffset,
                    std::ceil(spriteWidth), std::ceil(spriteHeight));
    return result;
}
sf::Sprite PMGame::View::SpriteSheet::GetSprite(const int& column, const int& row,
                                                const PMGame::Logic::Coordinate2D::Coordinate& projected) const {
    sf::Sprite result;
    const float spriteWidth =
        sf::Vector2f(sheet.getSize()).x / static_cast<float>(spritesPerColumn) - static_cast<float>(horizontalPadding);

    const float spriteHeight =
        sf::Vector2f(sheet.getSize()).y / static_cast<float>(spritesPerRow) - static_cast<float>(verticalPadding);

    result.setTexture(sheet);
    result.setTextureRect(GetTextureRect(column, row));

    result.setScale(projected.GetX() / std::ceil(spriteWidth), projected.GetY() / std::ceil(spriteHeight));

    return result;
}