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
                return result;
            }
            numToFind[target - v] = i;
        }
        return result;
    }
};

class Solution1Two
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> numToFind;

        for (int i = 0; i < nums.size(); ++i)
        {
            numToFind[nums[i]] = i;
        }
        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto diff = target - nums[i];
            const auto v = nums[i];
            if (numToFind.contains(diff) && numToFind[diff] != i) // Ensure indices are different
            {
                return {i, numToFind[diff]};
            }
        }
        return result;
    }
};
