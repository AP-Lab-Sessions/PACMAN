//

#ifndef PACMAN_GHOSTMODECHANGEEVENT_H
#define PACMAN_GHOSTMODECHANGEEVENT_H

#include "Pattern/Observer/Event/Event.h"

namespace PMGame::Logic {
enum GhostMode : short;

/**
 * @brief Called when the mode of a ghost got changed.
 */
struct GhostModeChangeEvent : public Event<GhostModeChangeEvent> {
    GhostMode newMode;
    explicit GhostModeChangeEvent(const GhostMode& newMode);
};
} // namespace PMGame::Logic

#endif // PACMAN_GHOSTMODECHANGEEVENT_H
