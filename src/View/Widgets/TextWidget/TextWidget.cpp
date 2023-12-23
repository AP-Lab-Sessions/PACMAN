//

#include "TextWidget.h"

sf::Text makeText(const std::string& str, const sf::Font& font, const sf::Color& fillColor, const int& size) {
    sf::Text text{str, font};
    text.setCharacterSize(size);
    text.setFillColor(fillColor);
    return text;
}

PMGame::View::TextWidget::TextWidget(const std::string& str, const sf::Font& font, const sf::Color& fillColor,
                                     const int& size, const sf::Vector2f& position) {
    text = makeText(str, font, fillColor, size);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(position);
}

bool PMGame::View::TextWidget::IsClicked(const sf::Vector2f& mousePos) const {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::FloatRect bounds = text.getGlobalBounds();
        if (bounds.contains(mousePos))
            return true;
    }
    return false;
}