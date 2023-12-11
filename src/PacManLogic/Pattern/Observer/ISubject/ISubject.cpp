//

#include "ISubject.h"

void PMLogic::ISubject::Attach(const std::weak_ptr<PMLogic::IObserver>& observer) {
    observers.push_back(observer);
}
void PMLogic::ISubject::Detach(const std::weak_ptr<PMLogic::IObserver>& observer) {
    for(auto iter=observers.begin(); iter!=observers.end();iter++) {
        if (iter->lock() == observer.lock())
            observers.erase(iter);
    }
}
