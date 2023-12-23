//

#include "World.h"
#include <fstream>

#include "Entity/DynamicEntity/PacMan/PacMan.h"

PMGame::Logic::World::World(std::unique_ptr<AbstractFactory>& factoryArg)
    : factory(std::move(factoryArg)), score(std::make_shared<Score>()), lives(std::make_shared<int>(3)) {

    std::ifstream levelFile(DEFAULT_LEVEL_PATH);
    if (levelFile) {
        std::string levelStr{std::istreambuf_iterator<char>(levelFile), std::istreambuf_iterator<char>()};
        level = std::make_shared<Level>(levelStr, factory, score, lives);
        level->Load();
    } else
        throw std::runtime_error("Cannot open level .txt file");
    levelFile.close();
}

void PMGame::Logic::World::Update() { level->Update(); }

int PMGame::Logic::World::GetScore() const { return score->GetScore(); }
int PMGame::Logic::World::GetLives() const { return *lives; }
void PMGame::Logic::World::SetPlayerDirection(const Coordinate2D::DiscreteDirection2D& direction) {
    const auto player = level->GetPlayer();
    if (!player.expired())
        player.lock()->SetNextDirection(direction);
}