#include <vector>

class Solution128
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        std::unordered_set vals(nums.begin(), nums.end());
        int longest = 0;

        for (const int& num : vals)
        {
            if (!vals.contains(num - 1))
            {
                int currentNum = num;
                int count = 1;

                while (vals.contains(currentNum + 1))
                {
                    currentNum += 1;
                    count += 1;
                }
                longest = std::max(longest, count);
            }
        }

        return longest;
    }
};
