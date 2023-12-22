PROJECT(PacManLogic)
SET(LOGIC_SRC Pattern/AbstractFactory/AbstractFactory.h
        Pattern/Observer/EventListener/IEventListener.h
        Pattern/Observer/Event/Event.h
        World/World.cpp
        PMLogic.h
        Helper/Random/Random.h Helper/Random/Random.cpp Helper/DeltaTime/DeltaTime.h Helper/DeltaTime/DeltaTime.cpp
        Score/Score.h Score/Scoreboard/Scoreboard.h Score/Scoreboard/Scoreboard.cpp Entity/Entity.h
        Helper/Camera/Camera.h Helper/Camera/Camera.cpp Coordinate/Coordinate.h Coordinate/Coordinate.cpp Entity/Entity.cpp
        Entity/DynamicEntity/DynamicEntity.h Entity/DynamicEntity/DynamicEntity.cpp
        Entity/StaticEntity/StaticEntity.h Entity/StaticEntity/StaticEntity.cpp
        Entity/StaticEntity/CollectableEntity/CollectableEntity.h
        Entity/StaticEntity/CollectableEntity/Fruit/Fruit.cpp Entity/StaticEntity/CollectableEntity/Fruit/Fruit.h
        Entity/StaticEntity/CollectableEntity/Coin/Coin.h Entity/StaticEntity/CollectableEntity/Coin/Coin.cpp
        Entity/StaticEntity/Wall/Wall.h Entity/StaticEntity/Wall/Wall.cpp Entity/StaticEntity/CollectableEntity/CollectableEntity.cpp
        Pattern/Visitor/IVisitor.h Entity/DynamicEntity/PacMan/PacMan.cpp Entity/DynamicEntity/AutomaticEntity/Ghost/Ghost.cpp
        World/Level/UpdateVisitor/UpdateVisitor.h World/Level/UpdateVisitor/UpdateVisitor.cpp
        Entity/IEntityVisitor/IEntityVisitor.h Entity/IEntityVisitor/IEntityVisitor.h
        Score/Score.cpp Events/EntityEvent/EntityPositionChangeEvent.h Events/EntityEvent/EntityDestroyEvent.h
        Events/EntityEvent/EntityCollectedEvent.h
        Entity/DynamicEntity/AutomaticEntity/AutomaticEntity.h Entity/DynamicEntity/AutomaticEntity/AutomaticEntity.cpp
         Events/EntityEvent/EntityDirectionChangeEvent.h Events/EntityEvent/EntityCreateEvent.h
        Events/EntityEvent/GhostEvent/GhostModeChangeEvent.h Events/EntityEvent/GhostEvent/GhostModeChangeEvent.cpp
        Pattern/Singleton/Singleton.h World/Level/Level.cpp Entity/StaticEntity/Intersection/Intersection.h Entity/StaticEntity/Intersection/Intersection.cpp)

add_executable(PacManLogicExec main.cpp ${LOGIC_SRC})
add_library(PacManLogicLib ${LOGIC_SRC})
target_include_directories(PacManLogicExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})