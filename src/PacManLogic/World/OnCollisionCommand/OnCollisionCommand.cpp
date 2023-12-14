//

#include "EntityOnCollisionCommand.h"
#include "Entity/DynamicEntity/PacMan/PacMan.h"
#include "Entity/StaticEntity/Wall/Wall.h"

template<>
void OnCollisionCommand<PacMan, Wall>::Execute() {

}