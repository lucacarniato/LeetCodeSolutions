using namespace std;

class Solution287
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int s = 0;
        int f = 0;
        while (true)
        {
            s = nums[s];
            f = nums[nums[f]];
            if (s == f)
            {
                break;
            }
        }

        int slow2 = 0;
        int res = 0;
        while (true)
        {
            s = nums[s];
            slow2 = nums[slow2];
            if (s == slow2)
            {
                res = s;
                break;
            }
        }
        return res;
    }
};
