#include <vector>

using namespace std;

class Solution153
{
public:
    int findMin(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int minVal = nums[0];
        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                minVal = std::min(minVal, nums[l]);
                break;
            }

            int mid = (l + r) / 2;
            minVal = std::min(minVal, nums[mid]);

            if (nums[mid] >= nums[l])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return minVal;
    }
};
