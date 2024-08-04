#include <queue>
#include <stack>

using namespace std;

class Solution853
{
    std::tuple<vector<int>, vector<int>> sortDescenting(vector<int>& position, vector<int>& speed)
    {
        // Create a vector of pairs (element, index)
        std::vector<std::pair<int, size_t>> elementIndexPairs(position.size());
        for (size_t i = 0; i < position.size(); ++i)
        {
            elementIndexPairs[i] = std::make_pair(position[i], i);
        }

        // Sort the vector of pairs based on the elements
        std::sort(elementIndexPairs.begin(), elementIndexPairs.end(),
                  [](const std::pair<int, size_t>& a, const std::pair<int, size_t>& b)
                  {
                      return a.first < b.first;
                  });

        // Extract the indices from the sorted pairs
        std::vector<size_t> sortedIndices(position.size());
        std::vector<int> newPosition(position.size());
        std::vector<int> newSpeed(position.size());
        for (size_t i = 0; i < elementIndexPairs.size(); ++i)
        {
            const auto index = elementIndexPairs[i].second;
            newPosition[i] = position[index];
            newSpeed[i] = speed[index];
        }

        return {newPosition, newSpeed};
    }

public:
    int carFleet(int target, vector<int>& p, vector<int>& s)
    {

        if (p.size() == 1)
        {
            return 1;
        }

        auto [position, speed] = sortDescenting(p, s);

        vector<double> timeToTarget(position.size(), 0.0);
        for (size_t i = 0; i < position.size(); ++i)
        {
            timeToTarget[i] = (target - position[i]) / static_cast<double>(speed[i]);
        }

        std::stack<double> st;
        st.push(timeToTarget[timeToTarget.size() - 1]);
        for (int i = timeToTarget.size() - 2; i >= 0; --i)
        {
            const auto& tt = st.top();

            if (timeToTarget[i] > tt)
            {
                st.push(timeToTarget[i]);
            }
        }
        return st.size();
    }
};
