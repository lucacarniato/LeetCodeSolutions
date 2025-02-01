#include <vector>

using namespace std;

class Solution33
{
public:
    int search(vector<int>& nums, int t)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == t)
            {
                return mid;
            }

            int lv = nums[l];
            int rv = nums[r];
            int midv = nums[mid];

            if (midv >= lv && (t >= lv && t <= midv))
            {
                r = mid - 1;
            }
            if (midv >= lv && !(t >= lv && t <= midv))
            {
                l = mid + 1;
            }

            if (rv >= midv && (t >= midv && t <= rv))
            {
                l = mid + 1;
            }
            if (rv >= midv && !(t >= midv && t <= rv))
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};
