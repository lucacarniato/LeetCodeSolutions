#include "shared/TreeNode.hpp"
#include "sliding_window/Solution121.cpp"
#include <vector>

int main()
{
    Solution121 solution;
    std::vector<int> prices{7, 1, 5, 3, 6, 4};

    auto result = solution.maxProfit(prices);

    return 0;
}
