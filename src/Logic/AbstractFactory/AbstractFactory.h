//

#ifndef PAC_MAN_ABSTRACTFACTORY_H
#define PAC_MAN_ABSTRACTFACTORY_H

#include <memory>
/**
 * @brief An abstract factory
 */
template<class EntityType>
class AbstractFactory {
public:
    /**
     * @brief Creates an object and gives away its ownership
     * @return Unique pointer to the object
     */
    virtual std::unique_ptr<EntityType> Create() const = 0;
};

#endif // PAC_MAN_ABSTRACTFACTORY_H
