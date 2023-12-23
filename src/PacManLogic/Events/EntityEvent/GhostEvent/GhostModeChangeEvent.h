//

#ifndef PACMAN_GHOSTMODECHANGEEVENT_H
#define PACMAN_GHOSTMODECHANGEEVENT_H

#include "Pattern/Observer/Event/Event.h"

enum GhostMode : short;

/**
 * @brief Called when the mode of a ghost got changed.
 */
struct GhostModeChangeEvent : public PMLogic::Event<GhostModeChangeEvent> {
    GhostMode newMode;
    explicit GhostModeChangeEvent(const GhostMode& newMode);
};

#endif // PACMAN_GHOSTMODECHANGEEVENT_H
