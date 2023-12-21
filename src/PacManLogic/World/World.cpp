//

#include "World.h"
#include <fstream>

#include "Entity/DynamicEntity/PacMan/PacMan.h"


PMLogic::World::World(std::unique_ptr<AbstractFactory> &factoryArg)
    : factory(std::move(factoryArg)),
     score(std::make_shared<Score>()),
      lives(std::make_shared<int>(3)) {

    std::ifstream levelFile(DEFAULT_LEVEL_PATH);
    std::string levelStr{std::istreambuf_iterator<char>(levelFile), std::istreambuf_iterator<char>()};
    levelFile.close();

    level = std::make_shared<Level>(levelStr, factory, score, lives);
    level->Load();
}

void PMLogic::World::Update() {
    level->Update();
}

int PMLogic::World::GetScore() const {
    return score->GetScore();
}
int PMLogic::World::GetLives() const {
    return *lives;
}
void PMLogic::World::SetPlayerDirection(const Coordinate2D::DiscreteDirection2D& direction) {
    const auto player = level->GetPlayer();
    if(!player.expired()) player.lock()->SetNextDirection(direction);
}