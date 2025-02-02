#include <vector>
using namespace std;

class Solution90
{
    void f(const vector<int>& nums, vector<vector<int>>& res, vector<int> sub, int p)
    {

        res.push_back(sub);
        for (int i = p; i < nums.size(); ++i)
        {
            if (i > p && nums[i] == nums[i - 1])
            {
                continue;
            }
            sub.push_back(nums[i]);
            f(nums, res, sub, i + 1);
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> s;
        sort(nums.begin(), nums.end());
        f(nums, res, s, 0);
        return res;
    }
};
