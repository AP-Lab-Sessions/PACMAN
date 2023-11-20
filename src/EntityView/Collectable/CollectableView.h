//

#ifndef PAC_MAN_COLLECTABLEVIEW_H
#define PAC_MAN_COLLECTABLEVIEW_H

#include "PMLogic.h"
#include "Observer/Observer.h"

class CollectableView : public PMLogic::Observer<PMLogic::Entity::Collectable> {

};

#endif // PAC_MAN_COLLECTABLEVIEW_H
