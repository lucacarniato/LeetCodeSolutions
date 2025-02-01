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
            int midv = nums[mid];
            if (midv == t)
            {
                return mid;
            }

            int lv = nums[l];
            int rv = nums[r];
            if (midv >= lv)
            {
                if (t >= lv && t < midv)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            if (rv >= midv)
            {
                if (t > midv && t <= rv)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
