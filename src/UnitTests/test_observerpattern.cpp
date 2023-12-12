//
#include <gtest/gtest.h>

#include "EntityView/View.h"
#include "EntityView/PacMan/PacManView.h"
#include "EntityFactory/EntityFactory.h"
#include <SFML/Graphics.hpp>

TEST(FactoryTest, BasicTest) {
    std::shared_ptr<std::vector<std::shared_ptr<IEntityObserver>>> views
        {new std::vector<std::shared_ptr<IEntityObserver>>()};
    std::shared_ptr<sf::RenderWindow> window;
    EntityFactory factory(views, window);
    EXPECT_NO_FATAL_FAILURE();
    EXPECT_NO_THROW();
}
