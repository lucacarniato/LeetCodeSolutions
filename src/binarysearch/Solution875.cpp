#include <vector>

using namespace std;

class Solution875
{
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l = 1;
        int r = std::ranges::max(piles);
        int result = 0;
        while (l <= r)
        {
            int s = (l + r) / 2;
            long long totalTime = 0;
            for (const auto& p : piles)
            {
                totalTime += std::ceil(static_cast<double>(p) / s);
            }

            if (totalTime <= h)
            {
                result = s;
                r = s - 1;
            }
            else
            {
                l = s + 1;
            }
        }

        return result;
    }
};
