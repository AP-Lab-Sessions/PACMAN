//

#include "Entity.h"

PMGame::Logic::Entity::Entity(PMGame::Logic::Coordinate2D::NormalizedCoordinate startPosition,
                              const PMGame::Logic::Coordinate2D::Coordinate& size)
    : position(std::move(startPosition)), size(size), onEntityDestroy(std::make_unique<EntityDestroyEvent>()),
      onEntityCreate(std::make_unique<EntityCreateEvent>(startPosition, size)) {}

PMGame::Logic::Coordinate2D::NormalizedCoordinate PMGame::Logic::Entity::GetPosition() const { return position; }

PMGame::Logic::Coordinate2D::Coordinate PMGame::Logic::Entity::GetSize() const { return size; }

void PMGame::Logic::Entity::Create() const { onEntityCreate->Notify(*onEntityCreate); }

PMGame::Logic::Entity::~Entity() { onEntityDestroy->Notify(*onEntityDestroy); }

void PMGame::Logic::Entity::CollideWith(Intersection&) {}

void PMGame::Logic::Entity::CollideWith(Coin&) {}

void PMGame::Logic::Entity::CollideWith(Wall&) {}

void PMGame::Logic::Entity::CollideWith(Fruit&) {}

void PMGame::Logic::Entity::CollideWith(Ghost&) {}

void PMGame::Logic::Entity::CollideWith(PacMan&) {}

void PMGame::Logic::Entity::Respawn() {}