add_subdirectory(PacManLogic)
add_subdirectory(lib/googletest)

SET(VIEW_SRC EntityView/Wall/WallView.cpp
        EntityView/PacMan/PacManView.cpp
        EntityView/Ghost/GhostView.cpp
        EntityView/Collectable/CollectableView.cpp
        )


add_executable(PacMan main.cpp ${VIEW_SRC})
target_link_libraries(PacMan PUBLIC PacManLogicLib sfml-system sfml-graphics sfml-window)
target_include_directories(PacManLogicLib PUBLIC PacManLogic)

SET(TESTS_SRC UnitTests/test_observerpattern.cpp)
add_executable(PacManTests UnitTests/test_main.cpp ${TESTS_SRC})
target_link_libraries(PacManTests PUBLIC PacManLogicLib gtest)
