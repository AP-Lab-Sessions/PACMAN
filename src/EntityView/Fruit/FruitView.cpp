//

#include "FruitView.h"
#include "Helper/Random/Random.h"

FruitView::FruitView(const std::weak_ptr<sf::RenderWindow> &window)
    : EntityView(window,12,PMLogic::Helper::Random::GetInstance().lock()->GetRandomInteger(0,6)) {}
