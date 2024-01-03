//

#include "World.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Helper/TimeManager/TimeManager.h"
#include <fstream>

using namespace std::filesystem;

PMGame::Logic::World::World(std::unique_ptr<AbstractFactory>& factoryArg)
    : currentDifficulty(0.7f), factory(std::move(factoryArg)), score(std::make_shared<Score>()),
      lives(std::make_shared<int>(3)),
      levelFiles(begin(directory_iterator(LEVEL_DIR)), end(directory_iterator(LEVEL_DIR))), currentLevelFileIndex(0) {
    std::sort(levelFiles.begin(), levelFiles.end());
    LoadNextLevel();
}

void PMGame::Logic::World::LoadNextLevel() {
    std::ifstream levelFile(levelFiles[currentLevelFileIndex].string());
    if (levelFile) {
        std::string levelStr{std::istreambuf_iterator<char>(levelFile), std::istreambuf_iterator<char>()};
        if (level)
            currentDifficulty *= 1.1;
        level = std::make_shared<Level>(levelStr, factory, score, lives, currentDifficulty);
        level->Load();
    } else
        throw std::runtime_error("Cannot open " + levelFiles[currentLevelFileIndex].string());
    levelFile.close();
    currentLevelFileIndex = (currentLevelFileIndex + 1) % static_cast<int>(levelFiles.size());
}
void PMGame::Logic::World::Update() {
    if (level->GetIsCompleted()) {
        PMGame::Logic::Helper::TimeManager::GetInstance().lock()->Pause();
        LoadNextLevel();
    }
    level->Update();
}

int PMGame::Logic::World::GetScore() const { return score->GetScore(); }
int PMGame::Logic::World::GetLives() const { return *lives; }
void PMGame::Logic::World::SetPlayerDirection(const Coordinate2D::DiscreteDirection2D& direction) {
    const auto player = level->GetPlayer();
    if (!player.expired())
        player.lock()->SetNextDirection(direction);
}