//

#include "World.h"
#include "Helper/DeltaTime/DeltaTime.h"
#include <fstream>

#include "Entity/DynamicEntity/PacMan/PacMan.h"


PMLogic::World::World(std::unique_ptr<AbstractFactory> &factoryArg)
    : factory(std::move(factoryArg)),
     score(std::make_shared<Score>()),
      lives(std::make_shared<int>(3)),
    currentDifficulty(1.0f) {

    std::ifstream levelFile(DEFAULT_LEVEL_PATH);
    std::string levelStr{std::istreambuf_iterator<char>(levelFile), std::istreambuf_iterator<char>()};
    levelFile.close();

    level = std::make_shared<Level>(levelStr, factory, score, lives, currentDifficulty);
    level->Load();
}

void PMLogic::World::Update() {
    std::weak_ptr<PMLogic::Helper::DeltaTime> stopWatch = PMLogic::Helper::DeltaTime::GetInstance();
    stopWatch.lock()->Tick();
    level->Update();
}

int PMLogic::World::GetScore() const {
    return score->GetScore();
}
int PMLogic::World::GetLives() const {
    return *lives;
}
void PMLogic::World::SetPlayerDirection(const DiscreteDirection2D& direction) {
    const auto player = level->GetPlayer();
    if(!player.expired()) player.lock()->SetNextDirection(direction);
}