//

#ifndef PACMAN_SINGLETON_H
#define PACMAN_SINGLETON_H

#include <memory>
#include "PMLogic.h"

// inspiration: https://stackoverflow.com/questions/51974670/implementing-singleton-with-crtp

template<typename Type>
class PMLogic::Singleton {
private:
    struct Type_Instance : public Type {
        Type_Instance() : Type() {}
    };
protected:
    Singleton() = default;

    static inline std::shared_ptr<Type> instance {nullptr};

public:
    virtual ~Singleton() = default;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static std::weak_ptr<Type> GetInstance() {
        if(instance == nullptr) {
            std::shared_ptr<Type> createdInstance{new Type_Instance()};
            instance = createdInstance;
        }
        return instance;
    }
};

#endif // PACMAN_SINGLETON_H
