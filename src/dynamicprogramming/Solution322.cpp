#include <vector>

using namespace std;

class Solution322
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        // 1st initialization
        for (int i = 0; i <= coins.size(); i++)
            dp[i][0] = 0;
        for (int j = 0; j <= amount; j++)
            dp[0][j] = INT_MAX - 1;
        // 2nd row initialization
        for (int j = 1; j <= amount; j++)
            if (j % coins[0] == 0)
                dp[1][j] = j / coins[0];
            else
                dp[1][j] = INT_MAX - 1;
        // unbounded knapsack code
        for (int i = 2; i <= coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        // if answer is possible or not
        if (dp[coins.size()][amount] == INT_MAX - 1)
            return -1;
        return dp[coins.size()][amount];
    }
};