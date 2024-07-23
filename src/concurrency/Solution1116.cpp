#include <atomic>

class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) 
    {
        for (int i = 0; i < n; ++i) 
        {
            while (flag.load(std::memory_order_acquire)!=0);
            printNumber(0); 
            currentNumber = currentNumber  + 1;
            if( currentNumber % 2 == 0)
            {
                flag.store(1,std::memory_order_release);
            }
            else
            {
                flag.store(-1,std::memory_order_release);
            }   
        }
    }

    void even(function<void(int)> printNumber) 
    {
        for (int i = 2; i <= n; i += 2) 
        {
            while (flag.load(std::memory_order_acquire)!=1);
            printNumber(i);
            flag.store(0, std::memory_order_release);
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2) 
        {
            while (flag.load(std::memory_order_acquire)!=-1);
            printNumber(i);
            flag.store(0, std::memory_order_release);
        }
    }

private:
    int currentNumber = 0;
    std::atomic<int> flag{0};
};