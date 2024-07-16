#include <vector>

using namespace std;

class Solution70
{

public:
    int climbStairs(int n)
    {
        vector<int> ncomb(n + 1, 1);

        for (int j = 2; j < ncomb.size(); ++j)
        {
            int sum = 0;
            for (int k = j - 1; k >= j - 2; k--)
            {
                sum += ncomb[k];
            }
            ncomb[j] = sum;
        }

        return ncomb[n];
    }
};
