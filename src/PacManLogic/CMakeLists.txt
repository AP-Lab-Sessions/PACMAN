PROJECT(PacManLogic)
SET(LOGIC_SRC AbstractFactory/AbstractFactory.h
        Pattern/Observer/IObserver/IObserver.h
        Pattern/Observer/ISubject/ISubject.h
        World/World.cpp
        PMLogic.h
        Helper/Random/Random.h Helper/Random/Random.cpp Helper/StopWatch/StopWatch.h Helper/StopWatch/StopWatch.cpp
        Score/Score.h Score/Scoreboard/Scoreboard.h Score/Scoreboard/Scoreboard.cpp Entity/Entity.h
        Helper/Camera/Camera.h Helper/Camera/Camera.cpp Coordinate/Coordinate.h Coordinate/Coordinate.cpp Entity/Entity.cpp
        Entity/DynamicEntity/DynamicEntity.h Entity/DynamicEntity/DynamicEntity.cpp Entity/StaticEntity/StaticEntity.h Entity/StaticEntity/StaticEntity.cpp Entity/StaticEntity/CollectableEntity/CollectableEntity.h Pattern/Observer/ISubject/ISubject.cpp Pattern/Observer/IObserver/IObserver.cpp
        Entity/StaticEntity/CollectableEntity/Fruit/Fruit.cpp Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h
        Entity/StaticEntity/CollectableEntity/Coin/Coin.h Entity/StaticEntity/CollectableEntity/Coin/Coin.cpp
        Entity/StaticEntity/Wall/Wall.h Entity/StaticEntity/Wall/Wall.cpp Entity/StaticEntity/CollectableEntity/CollectableEntity.cpp
        Pattern/Visitor/IVisitor/IVisitor.h Entity/DynamicEntity/PacMan/PacMan.cpp Entity/DynamicEntity/Ghost/Ghost.cpp
        Pattern/Command/ICommand/ICommand.h Pattern/Command/Invoker/Invoker.h
        World/UpdateVisitor/UpdateVisitor.h World/UpdateVisitor/UpdateVisitor.cpp
        Entity/IEntityVisitor/IEntityVisitor.h Entity/IEntityVisitor/IEntityVisitor.h
        World/EntityOnCollisionCommand/EntityOnCollisionCommand.h World/EntityOnCollisionCommand/EntityOnCollisionCommand.cpp
        Pattern/Command/Invoker/Invoker.cpp)

add_executable(PacManLogicExec main.cpp ${LOGIC_SRC})
add_library(PacManLogicLib ${LOGIC_SRC})
target_include_directories(PacManLogicExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})