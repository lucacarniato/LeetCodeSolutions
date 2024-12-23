#include <stack>
#include <vector>

class Solution84
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        std::stack<int> s;
        int result = 0;
        const auto n = heights.size();
        for (int i = 0; i <= n; ++i)
        {
            const auto currentHeight = i < n ? heights[i] : 0;
            while (!s.empty() && currentHeight < heights[s.top()])
            {
                const auto h = heights[s.top()];
                s.pop();
                const auto w = s.empty() ? i : i - s.top() - 1;
                result = std::max(result, w * h);
            }
            s.push(i);
        }
        return result;
    }
};
