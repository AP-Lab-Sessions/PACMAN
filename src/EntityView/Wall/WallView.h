//

#ifndef PAC_MAN_WALLVIEW_H
#define PAC_MAN_WALLVIEW_H

#include "Observer/Observer.h"
#include "PMLogic.h"

class WallView : public PMLogic::Observer<PMLogic::Entity::Wall> {};

#endif // PAC_MAN_WALLVIEW_H
