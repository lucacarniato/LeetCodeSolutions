#include <vector>
using namespace std;

class Solution78
{
    void subsets(const vector<int>& nums, vector<vector<int>>& res, vector<int> pSet, int p)
    {
        if (p > nums.size())
        {
            return;
        }

        if (p == nums.size() - 1)
        {
            res.push_back(pSet);
            pSet.push_back(nums[p]);
            res.push_back(pSet);
            return;
        }

        subsets(nums, res, pSet, p + 1);
        pSet.push_back(nums[p]);
        subsets(nums, res, pSet, p + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> pSet;
        subsets(nums, res, pSet, 0);
        return res;
    }
};
