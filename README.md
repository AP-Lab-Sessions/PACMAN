Project Advanced Programming 2023-2024
=======================================
### Name: Patryk Pilichowski
### Student number: s0220383

## Build & Installation
You can build the project out-of-source, install, and run it (make sure you're in the root directory first):
```
mkdir build -p
cd build && cmake .. && make && make install
cd .. && ./build/installed/bin/PacMan
```
The project has to be executed from root as well for the relative paths to work.
## Features
* Menu
  * Title text
  * Play button
  * Quit button
  * Top 5 highscores
* Level
  * Ghosts and PacMan movement
  * Entities that try to go out of bounds will end up in the opposite end of the map
  * Player movement control with arrows and WASD keys
  * Collisions with walls
  * Intersections
    * Invisible entities that help dynamic entities like pacman and ghosts 'snap' in the intersection coordinate such that they can fit through walls perfectly
  * Coin and fruit collecting
    * Preserved when PacMan loses a life
    * Respawn when PacMan collects everything
  * GhostAI
    * The ghosts begin with stasis mode where they wait
    * After a time they transition to chase mode where they choose directions based on the algorithm described in the assignment
    * Ghosts transition to a temporary fear mode when PacMan collects a fruit, their choice of direction differs distance-wise as described in the assignment
    * Ghosts choose a direction every time they encounter a wall or an intersection during chase and fear mode
  * Score
    * Score decreases over time.
    * The faster PacMan collected something consecutively, the greater the score
    * Entities have different score worth: Coins < fruits < ghosts
    * Score is preserved as long as PacMan's lives are not depleted
    * Score is saved to `src/config/highScore.json` if it's in the top 5
  * Player begins with 3 lives
    * Loses a single life when a ghost that is not in fear mode collides with PacMan
    * Game over state when all 3 lives have been used
  * Difficulty increases by a factor every time player goes to the next level
    * Ghosts become faster, fear mode duration is shorter
  * Player can safely pause and resume the game anytime
  * **Extra feature:** Multiple customizable levels playable throughout the game
    * Can be customized in `/levels/`
      * 'g' represents spawn for ghosts
      * '#' represents a wall
      * 'p' represents spawn for PacMan
      * '.' represents a coin
      * 'f' represents a fruit
      * ' ' represents empty space
    * Can be extended to procedural generation of the level text files
* Sprites
  * All entities (except intersections) have sprites
  * Dynamic entities like pacman and ghost have looping animations
    * Their sprite also changes if they change direction
* **Extra feature:** Audio
  * Different sound types play in parallel
    * When PacMan spawns
    * Eating a coin
    * Eating a fruit
    * Eating a ghost
## Known Issues
* OpenAL errors relating to SFML audio occur rarily. 
  * This issue seems machine dependent. 
  * It does not affect gameplay itself. However, it does make the time loading a level longer.
* Memory leaks seem to occur related to the graphics driver and the SFML library.
    * This issue seems machine dependent.
    * There are no known memory leaks related to the actual source code of the game.
    * The memory leaks may or may not be false positives.
* Collisions stop working properly if the game is ran at a very low framerate
  * This is because delta time is much larger and therefore 
  the position in the next update step of a dynamic entity may go over a wall 
  and collision may not be detected.
  * This seems to be a well-known problem in game development. However 
  because the project is more focused on the design patterns used the current collision detection system will remain unchanged.
* PacMan and the ghosts sometimes look 'laggy' for a moment when they make a turn
  * This is because when a dynamic entity wants to make a turn at an intersection they have to 'snap' on the intersection perfectly 
  so they can fit inbetween two walls
  * This will currently remain unchanged for the same reason as described above.

## Generating API Documentation
API documentation can be read in the source code itself but it can also be generated using _doxygen_ like this:
```
cd docs && doxygen docs.cfg
```
Again, ensure you're in the root directory first to run the command above. \
You can then view the locally created site by running this in /docs/html/:
```
browsername index.html
```
Where `browsername` is the installed browser of your choice, i.e `google-chrome`, `firefox`, etc...