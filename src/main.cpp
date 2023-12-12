#include "Game/Game.h"

// TODO: Exception handling, namespace encapsulation, check that all primitive types are explicitly initialized
int main() {
    Game game(800,600);
    game.Run();
    return EXIT_SUCCESS;
}
