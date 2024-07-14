#include <algorithm>
#include <vector>

using namespace std;

class Solution15
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        std::ranges::sort(nums);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    results.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                    {
                        l++;
                    }
                }
                else if (sum < 0)
                {
                    l++;
                }
                else if (sum > 0)
                {
                    r--;
                }
            }
        }

        return results;
    }
};
