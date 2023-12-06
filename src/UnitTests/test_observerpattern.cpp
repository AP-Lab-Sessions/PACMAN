//
#include <gtest/gtest.h>

#include "EntityView/View.h"
#include "EntityView/PacMan/PacManView.h"
#include "EntityFactory/EntityFactory.h"


TEST(ObserverPatternTest, BasicTest) {
    std::shared_ptr<std::vector<std::shared_ptr<PMLogic::IObserver>>> views
        {new std::vector<std::shared_ptr<PMLogic::IObserver>>()};
    EntityFactory factory(views);
    std::shared_ptr<PMLogic::Entity> pacMan = factory.CreatePacMan();
    pacMan->NotifyAll();
    EXPECT_NO_FATAL_FAILURE();
    EXPECT_NO_THROW();
}
