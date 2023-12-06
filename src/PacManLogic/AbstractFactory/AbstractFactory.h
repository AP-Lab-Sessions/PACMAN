//

#ifndef PAC_MAN_ABSTRACTFACTORY_H
#define PAC_MAN_ABSTRACTFACTORY_H

#include "PMLogic.h"
#include <memory>

class PMLogic::AbstractFactory {
public:
    virtual std::unique_ptr<PMLogic::Entity> CreatePacMan() const = 0;

    virtual std::unique_ptr<PMLogic::Entity> CreateGhost() const = 0;

    virtual std::unique_ptr<PMLogic::Entity> CreateWall() const = 0;

    virtual std::unique_ptr<PMLogic::Entity> CreateFruit() const = 0;

    virtual std::unique_ptr<PMLogic::Entity> CreateCoin() const = 0;

    /**
     * @brief Virtual destructor
     */
    virtual ~AbstractFactory() = default;
};

#endif // PAC_MAN_ABSTRACTFACTORY_H
