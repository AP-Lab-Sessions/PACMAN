//

#ifndef PAC_MAN_GHOSTVIEW_H
#define PAC_MAN_GHOSTVIEW_H

#include "Observer/Observer.h"
#include "PMLogic.h"

class GhostView : PMLogic::Observer<PMLogic::Entity::Ghost> {};

#endif // PAC_MAN_GHOSTVIEW_H
