#include <vector>

using namespace std;

class Solution46 {

    void f(vector<int>& nums, vector<vector<int>>& res, int index)
    {
        if(index >= nums.size())
        {
            res.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size();++i)
        {
            std::swap(nums[index],nums[i]);
            f(nums, res, index + 1);
            std::swap(nums[index],nums[i]);
        }
    }


public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        f(nums, res, 0);
        return res;
    }
};