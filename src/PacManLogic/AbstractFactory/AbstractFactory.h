//

#ifndef PAC_MAN_ABSTRACTFACTORY_H
#define PAC_MAN_ABSTRACTFACTORY_H

#include <memory>
#include "PMLogic.h"
/**
 * @brief An abstract factory
 */
template<typename Type>
class PMLogic::AbstractFactory {
public:
    /**
     * @brief Creates an object and gives away its ownership
     * @return Unique pointer to the object
     */
    virtual std::unique_ptr<Type> Create() const {
        return std::unique_ptr<Type>(new Type());
    }

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractFactory() = default;
};

#endif // PAC_MAN_ABSTRACTFACTORY_H
