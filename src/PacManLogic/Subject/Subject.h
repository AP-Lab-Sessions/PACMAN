//

#ifndef PAC_MAN_SUBJECT_H
#define PAC_MAN_SUBJECT_H

#include "PMLogic.h"
#include "Subject.h"
#include "Observer/Observer.h"
#include <vector>
#include <memory>

/**
 * @brief Templated subject class for the Observer design pattern.
 * @tparam Type The type.
 */
template<typename Type>
class PMLogic::Subject {
protected:
    std::vector<std::weak_ptr<PMLogic::Observer<Type>>> observers;
public:
    /**
     * @brief the virtual destructor.
     */
    virtual ~Subject() = default;
    /**
     * @brief Attaches a generic observer to the subject.
     * @param observer The attached observer.
     */
    virtual void Attach(const std::weak_ptr<PMLogic::Observer<Type>> &observer) {
        observers.push_back(observer);
    }
    /**
     * @brief Detaches a generic observer from the subject.
     * @param observer The detached observer.
     */
    virtual void Detach(const std::weak_ptr<PMLogic::Observer<Type>> &observer) {
        for(unsigned int i{0};i<observers.size();i++) {
            if(observers[i].lock() == observer.lock()) observers.erase(observers.begin()+i);
        }
    }
    /**
     * @brief Notifies or updates all attached observers with generic data.
     * @param data The data we want to update the observers with.
     */
    virtual void Notify(const Type &data) {
       for(auto currentObserver : observers) {
            currentObserver.lock()->Update(data);
       }
    }
};

#endif // PAC_MAN_SUBJECT_H
