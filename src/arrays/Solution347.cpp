#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution347
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> f;
        for (const auto& v : nums)
        {
            if (f.contains(v))
            {
                f[v] += 1;
            }
            else
            {
                f[v] = 1;
            }
        }

        auto comp = [&f](int n1, int n2)
        { return f[n1] > f[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for (const auto& [key, value] : f)
        {
            heap.push(key);
            if (heap.size() > k)
                heap.pop();
        }

        vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};
