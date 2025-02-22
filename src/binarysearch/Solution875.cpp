#include <vector>

using namespace std;

class Solution875
{
    long long f(vector<int>& piles, int k)
    {
        long long num_hours = 0;
        for (const auto p : piles)
        {
            num_hours += (p + k - 1) / k; // integer division here
        }
        return num_hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l = 1;
        int r = std::ranges::max(piles);
        int result = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            long long num_hours = f(piles, mid);
            if (num_hours <= h)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};
