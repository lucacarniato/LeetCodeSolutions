#include <stack>

class MyQueue232
{
    std::stack<int> push_stack_;
    std::stack<int> pop_stack_;

    void transfer()
    {
        if (pop_stack_.empty())
        {
            while (!push_stack_.empty())
            {
                pop_stack_.push(push_stack_.top());
                push_stack_.pop();
            }
        }
    }

public:
    MyQueue232()
    {
    }

    void push(int x)
    {
        push_stack_.push(x);
    }

    int pop()
    {
        transfer();
        int t = pop_stack_.top();
        pop_stack_.pop();
        return t;
    }

    int peek()
    {
        transfer();
        return pop_stack_.top();
    }

    bool empty()
    {
        return pop_stack_.empty() && push_stack_.empty();
    }
};
