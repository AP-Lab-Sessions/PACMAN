//

#ifndef INC_2023_PROJECT_MAGNUSTYMOTEUS_BUTTON_H
#define INC_2023_PROJECT_MAGNUSTYMOTEUS_BUTTON_H

#include <SFML/Graphics.hpp>

/**
 * @brief A 'wrapper' for sf::Text to make creating clickable texts (buttons) easier
 */
class TextWidget {
public:
    sf::Text text;

    /**
     * @param str The actual content
     * @param font The font
     * @param fillColor The fill color
     * @param size The size
     * @param position The position
     */
    TextWidget(const std::string &str, const sf::Font &font, const sf::Color &fillColor,
           const int &size,  const sf::Vector2f &position);

    /**
     * @brief Tells if the text is clicked on by the mouse given its position
     * @param mousePos the position of the mouse
     * @return boolean denoting if the mouse clicked on this text
     */
    bool IsClicked(const sf::Vector2f &mousePos) const;
};


#endif //INC_2023_PROJECT_MAGNUSTYMOTEUS_BUTTON_H
