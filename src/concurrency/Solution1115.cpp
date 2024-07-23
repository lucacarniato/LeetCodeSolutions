#include <condition_variable>
#include <mutex>

class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        fooPrinted = false;
    }

    void foo(function<void()> printFoo) {
        std::unique_lock<std::mutex> lock(m_);
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            condition_variable_.wait(lock, [this] { return !fooPrinted; });
        	printFoo();
            fooPrinted = true; 
            condition_variable_.notify_one();

        }
    }

    void bar(function<void()> printBar) {
         
        std::unique_lock<std::mutex> lock(m_);
        for (int i = 0; i < n; i++) {
        	// printBar() outputs "bar". Do not change or remove this line.
            
            condition_variable_.wait(lock, [this] { return fooPrinted; });
        	printBar();
            fooPrinted = false;
            condition_variable_.notify_one();
        }
    }
private:
    std::mutex m_;
    std::condition_variable condition_variable_;
    bool fooPrinted = false;
};