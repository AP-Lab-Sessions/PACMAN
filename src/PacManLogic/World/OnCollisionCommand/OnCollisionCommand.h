//

#ifndef PACMAN_ONCOLLISIONCOMMAND_H
#define PACMAN_ONCOLLISIONCOMMAND_H

#include <vector>
#include "Pattern/Command/ICommand.h"
#include "PMLogic.h"

class PacMan;
class Ghost;
class CollectableEntity;

class OnCollisionCommand : public PMLogic::ICommand<OnCollisionCommand> {
protected:

    std::vector<std::reference_wrapper<const PMLogic::Entity>> &destructables;

public:
    explicit OnCollisionCommand(std::vector<std::reference_wrapper<const PMLogic::Entity>> &destructables);

    void Execute() override;
    void ExecuteAndNotify() override;

    void SetColliders(PacMan &pacMan, Ghost &ghost);
    void SetColliders(const CollectableEntity &collectable);
};
#endif //PACMAN_ONCOLLISIONCOMMAND_H
