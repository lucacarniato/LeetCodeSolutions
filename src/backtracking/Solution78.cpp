#include <vector>
using namespace std;

class Solution78
{
    void backtrack(const vector<int>& nums, vector<vector<int>>& res, vector<int>& pSet, int p)
    {
        if (p == nums.size())
        {
            res.push_back(pSet);
            return;
        }

        backtrack(nums, res, pSet, p + 1);

        pSet.push_back(nums[p]);
        backtrack(nums, res, pSet, p + 1);

        pSet.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> pSet;
        backtrack(nums, res, pSet, 0);
        return res;
    }
};
