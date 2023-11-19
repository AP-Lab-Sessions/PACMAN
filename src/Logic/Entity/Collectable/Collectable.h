//

#ifndef PAC_MAN_COLLECTABLE_H
#define PAC_MAN_COLLECTABLE_H

#include "Subject/Subject.h"

class Collectable : public Subject<Collectable> {
public:
    ~Collectable() override = default;
};

#endif // PAC_MAN_COLLECTABLE_H
