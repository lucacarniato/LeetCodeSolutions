#include <vector>
using namespace std;

class Solution40
{
    void subsets(const vector<int>& nums, vector<vector<int>>& res, vector<int>& pSet, int pos, int sum)
    {
        if (sum == 0)
        {
            res.push_back(pSet);
            return;
        }

        for (int i = pos; i < nums.size(); ++i)
        {
            if (i > pos && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > sum)
                break;

            pSet.push_back(nums[i]);
            subsets(nums, res, pSet, i + 1, sum - nums[i]);
            pSet.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> pSet;
        sort(candidates.begin(), candidates.end());
        subsets(candidates, res, pSet, 0, target);
        return res;
    }
};
