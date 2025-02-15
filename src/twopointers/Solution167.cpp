#include <vector>

using namespace std;

class Solution167
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> result;
        if (r == l)
        {
            return result;
        }

        while (r > l)
        {
            int sum = numbers[r] + numbers[l];
            if (sum == target)
            {
                result = vector<int>{l + 1, r + 1};
                break;
            }

            if (sum > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return result;
    }
};
