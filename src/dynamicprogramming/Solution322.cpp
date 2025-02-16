#include <vector>

using namespace std;

class Solution322
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        std::vector<int> solutions(amount + 1, amount + 1);
        solutions[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (const auto& c : coins)
            {
                const int target = i - c;
                if (target >= 0)
                {
                    solutions[i] = std::min(solutions[i], 1 + solutions[target]);
                }
            }
        }
        return solutions[amount] == amount + 1 ? -1 : solutions[amount];
    }
};

class Solution322RecursionTopDown
{

    std::unordered_map<int, int> m_;

    int f(vector<int>& coins, int target)
    {
        if (target == 0)
        {
            return 0;
        }

        int flag = std::numeric_limits<int>::max();
        if (target < 0)
        {
            return flag;
        }

        if (m_.contains(target))
        {
            return m_[target];
        }

        int min_coins = flag;
        for (int coin : coins)
        {
            int new_target = target - coin;
            int res = f(coins, new_target);
            if (res != flag)
            { // Ensure valid path
                min_coins = min(min_coins, 1 + res);
            }
        }

        m_[target] = min_coins;
        return min_coins;
    }

public:
    int coinChange(vector<int>& coins, int amount)
    {
        int flag = std::numeric_limits<int>::max();
        int min_change = f(coins, amount);
        return (min_change == flag) ? -1 : min_change;
    }
};
