#include <unordered_map>
#include <vector>

using namespace std;

class Solution1
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> numToFind;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            const auto v = nums[i];
            if (numToFind.contains(v))
            {
                result.emplace_back(numToFind[v]);
                result.emplace_back(i);
            }
            numToFind[target - v] = i;
        }
        return result;
    }
};
