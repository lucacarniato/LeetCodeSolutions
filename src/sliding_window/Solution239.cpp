#include <deque>

using namespace std;

class Solution239
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> result;
        if (k > nums.size())
        {
            return result;
        }

        std::deque<size_t> q;
        size_t l = 0;
        size_t r = 0;
        while (r < nums.size())
        {
            while (!q.empty() && nums[q.back()] < nums[r])
            {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front())
            {
                q.pop_front();
            }

            if (r + 1 >= static_cast<size_t>(k))
            {
                result.push_back(nums[q.front()]);
                l += 1;
            }
            r += 1;
        }
        return result;
    }
};
