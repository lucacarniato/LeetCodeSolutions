#include <condition_variable>
#include <mutex>

class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        std::scoped_lock lock{m_};
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstCalled = true;
        first_condition_variable_.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock lock{m_};
        first_condition_variable_.wait(lock, [this] { return firstCalled; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondCalled = true;
        second_condition_variable_.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock lock{m_};
        second_condition_variable_.wait(lock, [this] { return secondCalled; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    std::mutex m_;
    bool firstCalled = false;
    bool secondCalled = false;
    bool thirdCalled = false;
    std::condition_variable first_condition_variable_;
    std::condition_variable second_condition_variable_;

};