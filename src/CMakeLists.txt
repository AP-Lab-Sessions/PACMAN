add_subdirectory(PacManLogic)
add_subdirectory(lib/googletest)

SET(VIEW_SRC EntityView/PacMan/PacManView.cpp EntityFactory/EntityFactory.h EntityFactory/EntityFactory.h
        EntityFactory/EntityFactory.h EntityFactory/EntityFactory.cpp
        Game/Game.h EntityView/Ghost/GhostView.h EntityView/Fruit/FruitView.h
        EntityView/Coin/CoinView.h EntityView/Wall/WallView.h EntityView/View.h
        State/State.h State/State.cpp
        State/StateManager/StateManager.h State/StateManager/StateManager.cpp
        State/MenuState/MenuState.h State/MenuState/MenuState.cpp Game/Game.cpp Game/Assets.h Game/Assets.cpp)


add_executable(PacMan main.cpp ${VIEW_SRC})
target_link_libraries(PacMan PUBLIC PacManLogicLib sfml-system sfml-graphics sfml-window)
target_include_directories(PacManLogicLib PUBLIC PacManLogic ${CMAKE_CURRENT_SOURCE_DIR})

SET(TESTS_SRC UnitTests/test_observerpattern.cpp)
add_executable(PacManTests UnitTests/test_main.cpp ${VIEW_SRC} ${TESTS_SRC})
target_link_libraries(PacManTests PUBLIC PacManLogicLib gtest sfml-system sfml-graphics sfml-window)
