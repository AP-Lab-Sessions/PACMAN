PROJECT(PacManLogic)
SET(LOGIC_SRC AbstractFactory/AbstractFactory.h
        Observer/Observer.h
        Subject/Subject.h
        World/World.cpp
        Entity/Wall/Wall.cpp
        Entity/PacMan/PacMan.cpp
        Entity/Ghost/Ghost.cpp
        Entity/Collectable/Collectable.cpp
        Entity/Collectable/Coin/Coin.cpp
        Entity/Collectable/Fruit/Fruit.cpp
        PMLogic.h
        Helper/Random/Random.h Helper/Random/Random.cpp Helper/StopWatch/StopWatch.h Helper/StopWatch/StopWatch.cpp
        Score/Score.h Score/Scoreboard/Scoreboard.h Score/Scoreboard/Scoreboard.cpp Entity/Entity.h)

add_executable(PacManLogicExec main.cpp ${LOGIC_SRC})
add_library(PacManLogicLib ${LOGIC_SRC})
target_include_directories(PacManLogicExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})