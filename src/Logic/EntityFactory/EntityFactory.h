//

#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>

/**
 * @brief Generic abstract factory
 * @tparam EntityType Entity type the factory will be able to produce
 */
template<class EntityType>
class EntityFactory {
public:
    /**
     * @brief Creates a generic entity and gives away its ownership
     * @return Unique pointer to the created entity
     */
    virtual std::unique_ptr<EntityType> CreateEntity() const = 0;
    /**
     * @brief Virtual destructor
     */
    virtual ~EntityFactory() = default;
};
#endif