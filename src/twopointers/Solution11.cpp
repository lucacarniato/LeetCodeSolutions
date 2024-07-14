#include <vector>
#include <ranges>

using namespace std;

class Solution11
{
public:
    int maxArea(vector<int>& height)
    {

        int l = 0;
        int r = height.size() - 1;
        int result = 0;
        while (r > l)
        {
            int currentArea = (r - l) * std::min(height[l], height[r]);
            result = std::max(result, currentArea);
            if (height[l] <= height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return result;
    }
};