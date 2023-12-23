//

#ifndef PACMAN_SINGLETON_H
#define PACMAN_SINGLETON_H

#include <memory>
#include "PMLogic.h"

// inspiration: https://stackoverflow.com/questions/51974670/implementing-singleton-with-crtp

/**
     * @brief A singleton that uses CRTP such that concrete singletons can derived from it and avoid repetition
     * @tparam Type
 */
template<typename Type>
class PMLogic::Singleton {
private:
    /**
     * @brief Used for calling the constructor of Type for GetInstance()
     */
    struct Type_Instance : public Type {
        Type_Instance() : Type() {}
    };
protected:
    Singleton() = default;

    /**
     * @brief single instance of Type
     */
    static inline std::shared_ptr<Type> instance {nullptr};

public:
    virtual ~Singleton() = default;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    /**
     * @brief Returns the single instance of Type.
     * @return The single instance of Type.
     */
    static std::weak_ptr<Type> GetInstance() {
        if(instance == nullptr) {
            std::shared_ptr<Type> createdInstance{new Type_Instance()};
            instance = createdInstance;
        }
        return instance;
    }
};

#endif // PACMAN_SINGLETON_H
