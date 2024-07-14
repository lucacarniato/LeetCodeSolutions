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

            int tofind = target - numbers[l];
            while (r > l && numbers[r] > tofind)
            {
                r--;
            }

            if (numbers[r] == tofind)
            {
                result = vector<int>{l + 1, r + 1};
                break;
            }
            l++;
        }

        return result;
    }
};