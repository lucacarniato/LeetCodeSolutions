#include <queue>
#include <stack>

using namespace std;

class Solution749
{
public:
    vector<int> dailyTemperatures(vector<int>& temp)
    {
        vector<int> result(temp.size(), 0);

        std::stack<std::pair<int, int>> s;

        s.push({temp[0], 0});

        for (int i = 1; i < temp.size(); ++i)
        {
            while (!s.empty())
            {
                const auto& [ct, ci] = s.top();
                if (temp[i] > ct)
                {
                    result[ci] = i - ci;
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            s.push({temp[i], i});
        }

        return result;
    }
};
