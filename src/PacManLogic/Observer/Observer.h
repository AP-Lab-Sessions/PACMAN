//

#ifndef PAC_MAN_OBSERVER_H
#define PAC_MAN_OBSERVER_H

#include "PMLogic.h"

/**
 * @brief Generic observer interface for the Observer design pattern.
 * @tparam Type The generic type.
 */
template<typename Type>
class PMLogic::Observer {
public:
    /**
     * @brief The virtual destructor.
     */
    virtual ~Observer() = default;
    /**
     * @brief Gets updated according to given generic data.
     * @param data The given data.
     */
    virtual void Update(const Type &data) = 0;
};

#endif // PAC_MAN_OBSERVER_H
