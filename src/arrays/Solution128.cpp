#include <set>
#include <vector>

class Solution128
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        std::set<int> vals;
        for (auto& v : nums)
        {
            vals.emplace(v);
        }

        int count = 1;
        int result = 0;
        for (const auto& v : vals)
        {

            if (!vals.contains(v - 1))
            {
                result = std::max(result, count);
                count = 1;
            }
            else
            {
                count = count + 1;
            }
        }
        return std::max(result, count);
    }
};
