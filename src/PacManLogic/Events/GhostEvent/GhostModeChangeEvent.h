//

#ifndef PACMAN_GHOSTMODECHANGEEVENT_H
#define PACMAN_GHOSTMODECHANGEEVENT_H

#include "Pattern/Observer/Event/Event.h"

enum GhostMode : short;

struct GhostModeChangeEvent : public PMLogic::Event<GhostModeChangeEvent> {
    GhostMode newMode;
    explicit GhostModeChangeEvent(const GhostMode &newMode);
};

#endif // PACMAN_GHOSTMODECHANGEEVENT_H
