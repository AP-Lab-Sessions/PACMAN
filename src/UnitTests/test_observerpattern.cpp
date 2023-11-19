//
#include "Observer/Observer.h"
#include "Subject/Subject.h"
#include <gtest/gtest.h>

class SomeObject : public Subject<SomeObject> {
public:
    const std::string someData;
    explicit SomeObject(const std::string &someData) : someData(someData) {}
};

class TestObserver : public Observer<SomeObject> {
public:
    void Update(const SomeObject &obj) final {
        std::cout << "Oh no: " << obj.someData << std::endl;
    }
};

TEST(ObserverPatternTest, BasicTest) {
    std::shared_ptr<TestObserver> o{new TestObserver};
    std::shared_ptr<TestObserver> o2{new TestObserver};
    SomeObject s{"Something"};
    s.Attach(o);
    s.Attach(o2);
    s.Notify(s);
    EXPECT_NO_FATAL_FAILURE();
    EXPECT_NO_THROW();
}
