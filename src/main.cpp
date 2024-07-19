#include "stack/Solution150.cpp"

#include <string>
#include <vector>

int main()
{
    Solution150 solution;
    std::vector<std::string> test{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    const auto result = solution.evalRPN(test);

    return 0;
}
