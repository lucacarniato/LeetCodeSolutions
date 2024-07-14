#include <vector>
using namespace std;

class Solution238
{
public:
    std::vector<int> productExceptSelf(vector<int>& nums)
    {
        vector result(nums.size(), 1);

        int previousPrefix = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            result[i] = result[i] * previousPrefix;
            previousPrefix = previousPrefix * nums[i];
        }
        int previousPostfix = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            result[i] = result[i] * previousPostfix;
            previousPostfix = previousPostfix * nums[i];
        }
        return result;
    }
};
