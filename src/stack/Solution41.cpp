#include <queue>
#include <stack>

using namespace std;

class Solution749
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> s;
        s.push(0);
        int tp = 0;

        vector<int> result(temperatures.size(), 0);

        /*
        while (tp + 1 < temperatures.size())
        {
            auto sindex = s.top();
            if (temperatures[tp + 1] <= temperatures[sindex])
            {
                s.push(sindex + 1);
                tp = tp + 1;
            }
            else
            {
                while (temperatures[tp + 1] > temperatures[sindex])
                {
                    s.pop();
                    sindex = s.top();
                    result[sindex] = s.size();

                    index--;
                    s.pop();
                    nd++;
                }
                if (s.empty())
                {
                    nd = 1;
                }
            }
        }
        */
        return result;
    }
};
