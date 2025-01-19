#include <vector>

using namespace std;

class Solution74
{
    int search(vector<int>& nums, int target)
    {

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        bool found = false;
        for (auto& row : matrix)
        {
            if (target >= row.front() && target <= row.back())
            {
                found = search(row, target) != -1;
            }
        }
        return found;
    }
};
