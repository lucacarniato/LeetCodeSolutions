using namespace std;

class Solution34
{
    vector<int> findRange(const vector<int>& nums, int target, int m)
    {
        int ml = m;
        while (ml - 1 >= 0 && nums[ml - 1] == target)
        {
            ml = ml - 1;
        }
        int mr = m;
        while (mr + 1 < nums.size() && nums[mr + 1] == target)
        {
            mr = mr + 1;
        }
        return {ml, mr};
    }

public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return {-1, -1};
        }
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            if (nums[l] == target)
            {
                return findRange(nums, target, l);
            }
            if (nums[r] == target)
            {
                return findRange(nums, target, r);
            }
            int m = (l + r) / 2;
            if (nums[m] == target)
            {
                return findRange(nums, target, m);
            }

            if (target > nums[m])
            {
                l = m + 1;
            }
            else if (target < nums[m])
            {
                r = m - 1;
            }
        }

        return {-1, -1};
    }
};
