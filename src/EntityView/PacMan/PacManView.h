//

#ifndef PAC_MAN_PACMANVIEW_H
#define PAC_MAN_PACMANVIEW_H

#include "Observer/Observer.h"
#include "PMLogic.h"

class PacManView : public PMLogic::Observer<PMLogic::Entity::PacMan> {};

#endif // PAC_MAN_PACMANVIEW_H
