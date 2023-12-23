add_subdirectory(Logic)

SET(VIEW_SRC View/EntityView/DynamicEntityView/PacMan/PacManView.cpp EntityFactory/EntityFactory.h EntityFactory/EntityFactory.h
        EntityFactory/EntityFactory.h EntityFactory/EntityFactory.cpp
        Game/Game.h
        View/EntityView/DynamicEntityView/Ghost/GhostView.h View/EntityView/DynamicEntityView/Ghost/GhostView.cpp
        View/EntityView/Fruit/FruitView.h View/EntityView/Fruit/FruitView.cpp
        View/EntityView/Coin/CoinView.h View/EntityView/Coin/CoinView.cpp
        View/EntityView/Wall/WallView.h View/EntityView/Wall/WallView.cpp
        View/EntityView/EntityView.h
        View/State/State.h View/State/State.cpp
        View/StateManager/StateManager.h View/StateManager/StateManager.cpp
        View/State/MenuState/MenuState.h View/State/MenuState/MenuState.cpp Game/Game.cpp
        View/Widgets/TextWidget/TextWidget.h View/Widgets/TextWidget/TextWidget.cpp
        View/State/LevelState/LevelState.h View/State/LevelState/LevelState.cpp
        View/SpriteSheet/SpriteSheet.h View/SpriteSheet/SpriteSheet.cpp
        View/EntityView/DynamicEntityView/DynamicEntityView.h View/EntityView/EntityView.cpp View/EntityView/DynamicEntityView/DynamicEntityView.cpp View/State/PausedState/PausedState.h View/State/PausedState/PausedState.cpp View/State/GameOverState/GameOverState.h View/State/GameOverState/GameOverState.cpp View/SoundManager/SoundManager.h View/SoundManager/SoundManager.cpp)


add_executable(PacMan main.cpp ${VIEW_SRC})
target_link_libraries(PacMan PUBLIC PacManLogicLib sfml-system sfml-graphics sfml-window sfml-audio)
target_include_directories(PacManLogicLib PUBLIC Logic ${CMAKE_CURRENT_SOURCE_DIR})
