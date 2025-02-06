#include <queue>
#include <stack>

using namespace std;

class Solution853
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        if (position.empty())
        {
            return 0;
        }

        // sort in descending order
        std::vector<std::pair<int, int>> positionsSpeed;
        for (size_t i = 0; i < position.size(); ++i)
        {
            positionsSpeed.emplace_back(position[i], speed[i]);
        }
        std::sort(positionsSpeed.begin(), positionsSpeed.end(), [](const auto& a, const auto& b)
                  { return a.first > b.first; });

        std::vector<double> timeToTravel;
        for (const auto& [pos, spd] : positionsSpeed)
        {
            timeToTravel.push_back((double)(target - pos) / spd);
        }

        std::stack<double> s;
        for (double tt : timeToTravel)
        {
            if (s.empty() || tt > s.top())
            {
                s.push(tt);
            }
        }
        return s.size();
    }
};
