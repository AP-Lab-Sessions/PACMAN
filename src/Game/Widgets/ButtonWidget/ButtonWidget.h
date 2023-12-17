//

#ifndef INC_2023_PROJECT_MAGNUSTYMOTEUS_BUTTON_H
#define INC_2023_PROJECT_MAGNUSTYMOTEUS_BUTTON_H

#include <SFML/Graphics.hpp>

class ButtonWidget {
public:
    sf::Text text;

    ButtonWidget(const std::string &str, const sf::Font &font, const sf::Color &fillColor,
           const int &size,  const sf::Vector2f &position);
    bool IsClicked(const sf::Vector2f &mousePos) const;
};


#endif //INC_2023_PROJECT_MAGNUSTYMOTEUS_BUTTON_H
