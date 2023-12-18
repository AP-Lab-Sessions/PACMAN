#include "Game/Game.h"

// TODO: Intersection detection for both pacman and ghost,
//  game over and victory,
//  next level, audio, documentation,
//  Exception handling,
//  namespace encapsulation,
//  check that all primitive types are explicitly initialized
int main() {
    Game game(960,540);
    game.Run();
    return EXIT_SUCCESS;
}
