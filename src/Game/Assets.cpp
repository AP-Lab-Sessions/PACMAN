//

#include "Assets.h"

std::shared_ptr<Assets> Assets::instance {nullptr};

Assets::Assets() {
    if (!mainFont.loadFromFile("assets/fonts/Pacmania.otf")) throw std::runtime_error("Can't import necessary font!");
}

std::weak_ptr<Assets> Assets::GetInstance() {
    if(instance == nullptr) {
        std::shared_ptr<Assets> createdInstance{new Assets()};
        instance = createdInstance;
    }
    return instance;
}

sf::Font Assets::GetMainFont() const {
    return mainFont;
}
