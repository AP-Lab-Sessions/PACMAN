//
#include "Observer/Observer.h"
#include "Subject/Subject.h"
#include <gtest/gtest.h>

class TestObserver : public Observer<std::string> {
public:
    void Update(const std::string &data) final {
        std::cout << "Oh no: " << data << std::endl;
    }
};
class TestSubject : public Subject<std::string> {
public:
    void something() {
        Notify("Something happened man!");
    }
};

TEST(ObserverPatternTest, BasicTest) {
    std::shared_ptr<TestObserver> o{new TestObserver};
    std::shared_ptr<TestObserver> o2{new TestObserver};
    TestSubject s;
    s.Attach(o);
    s.Attach(o2);
    s.something();
    EXPECT_NO_FATAL_FAILURE();
    EXPECT_NO_THROW();
}
