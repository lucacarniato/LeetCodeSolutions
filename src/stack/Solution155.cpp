#include <stack>

using namespace std;

class MinStack
{
    std::stack<int> minVal_;
    std::stack<int> vals_;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        vals_.push(val);
        if (minVal_.empty())
        {
            minVal_.push(val);
            return;
        }
        const auto minVal = minVal_.top();
        if (val >= minVal)
        {
            minVal_.push(minVal);
        }
        else
        {
            minVal_.push(val);
        }
    }

    void pop()
    {
        vals_.pop();
        minVal_.pop();
    }

    int top()
    {
        auto val = vals_.top();
        return val;
    }

    int getMin()
    {
        const auto minVal = minVal_.top();
        return minVal;
    }
};
