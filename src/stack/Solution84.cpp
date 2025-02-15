#include <stack>
#include <vector>

class Solution84
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        std::stack<int> s;
        int result = 0;
        for (int i = 0; i <= heights.size(); ++i)
        {
            const auto h = i == heights.size() ? 0 : heights[i];

            while (!s.empty() && h < heights[s.top()])
            {
                int rectangle_height = heights[s.top()];
                s.pop();
                int rectangle_width = s.empty() ? i : i - s.top() - 1;
                result = std::max(result, rectangle_height * rectangle_width);
            }
            s.push(i);
        }
        return result;
    }
};
