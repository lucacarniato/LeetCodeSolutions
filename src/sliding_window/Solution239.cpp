#include <deque>

using namespace std;

class Solution239
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::deque<int> dq;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
