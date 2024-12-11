#include <algorithm>
#include <numeric>
#include <vector>

class Solution121
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        if (prices.size() <= 1)
        {
            return 0;
        }

        int result = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {

            if (prices[i] > min_price)
            {
                result = std::max(result, prices[i] - min_price);
            }
            else
            {
                min_price = prices[i];
            }
        }
        return result;
    }
};
