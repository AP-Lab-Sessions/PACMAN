//

#ifndef PAC_MAN_COLLECTABLEVIEW_H
#define PAC_MAN_COLLECTABLEVIEW_H

#include "Entity/Collectable/Collectable.h"
#include "Observer/Observer.h"

class CollectableView : public Observer<Collectable> {};

#endif // PAC_MAN_COLLECTABLEVIEW_H
