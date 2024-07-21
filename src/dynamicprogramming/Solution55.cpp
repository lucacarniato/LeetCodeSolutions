#include <vector>

using namespace std;

class Solution55
{

public:
    bool canJump(vector<int>& nums)
    {
        int target = nums.size() - 1;
        
        for(int i = nums.size()-1; i>=0;--i)
        {
            if(nums[i] + i >= target)
            {
                target = i;
                if(target == 0)
                {
                    return true;
                }
                
            }
            
        }
        return false;
        
        
    }
};

class Solution55Second
{
    std::vector<int> res;

    bool f(const vector<int>& nums, size_t ind)
    {
        if (res[ind] != -1)
        {
            return res[ind] == 1;
        }

        if (ind >= nums.size())
        {
            res[ind] = 0;
            return false;
        }
        if (ind == nums.size() - 1)
        {
            res[ind] = 1;
            return true;
        }

        for (size_t i = 1; i <= nums[ind]; ++i)
        {
            auto r = f(nums, ind + i);
            if (r)
            {
                res[ind] = 1;
                return true;
            }
        }
        if (res[ind] == -1)
        {
            res[ind] = 0;
            return false;
        }
        return false;
    }

public:
    bool canJump(vector<int>& nums)
    {
        res.resize(nums.size());
        std::fill(res.begin(), res.end(), -1);
        auto r = f(nums, 0);
        return r;
    }
};
