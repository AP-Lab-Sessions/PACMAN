PROJECT(PacManLogic)
SET(LOGIC_SRC AbstractFactory/AbstractFactory.h
        Pattern/Observer/EventListener/IEventListener.h
        Pattern/Observer/Event/Event.h
        World/World.cpp
        PMLogic.h
        Helper/Random/Random.h Helper/Random/Random.cpp Helper/StopWatch/StopWatch.h Helper/StopWatch/StopWatch.cpp
        Score/Score.h Score/Scoreboard/Scoreboard.h Score/Scoreboard/Scoreboard.cpp Entity/Entity.h
        Helper/Camera/Camera.h Helper/Camera/Camera.cpp Coordinate/Coordinate.h Coordinate/Coordinate.cpp Entity/Entity.cpp
        Entity/DynamicEntity/DynamicEntity.h Entity/DynamicEntity/DynamicEntity.cpp
        Entity/StaticEntity/StaticEntity.h Entity/StaticEntity/StaticEntity.cpp
        Entity/StaticEntity/CollectableEntity/CollectableEntity.h
        Entity/StaticEntity/CollectableEntity/Fruit/Fruit.cpp Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h
        Entity/StaticEntity/CollectableEntity/Coin/Coin.h Entity/StaticEntity/CollectableEntity/Coin/Coin.cpp
        Entity/StaticEntity/Wall/Wall.h Entity/StaticEntity/Wall/Wall.cpp Entity/StaticEntity/CollectableEntity/CollectableEntity.cpp
        Pattern/Visitor/IVisitor.h Entity/DynamicEntity/PacMan/PacMan.cpp Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.cpp
        Pattern/Command/ICommand.h
        World/UpdateVisitor/UpdateVisitor.h World/UpdateVisitor/UpdateVisitor.cpp
        Entity/IEntityVisitor/IEntityVisitor.h Entity/IEntityVisitor/IEntityVisitor.h
        World/OnCollisionCommand/OnCollisionCommand.h World/OnCollisionCommand/OnCollisionCommand.cpp
        Score/Score.cpp Events/EntityEvent/EntityPositionChangeEvent.h Events/EntityEvent/EntityDestroyEvent.h
        Events/EntityEvent/EntityCollectedEvent.h Entity/DynamicEntity/AutomaticEntity/AutomaticEntity.h Entity/DynamicEntity/AutomaticEntity/AutomaticEntity.cpp
        Events/EntityEvent/EntityCollectedEvent.cpp)

add_executable(PacManLogicExec main.cpp ${LOGIC_SRC})
add_library(PacManLogicLib ${LOGIC_SRC})
target_include_directories(PacManLogicExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})