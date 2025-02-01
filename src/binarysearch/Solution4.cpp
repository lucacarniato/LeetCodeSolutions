#include <ranges>
#include <vector>

using namespace std;

class Solution4
{
    double FindMedian(const vector<int>& a, const vector<int>& b)
    {
        int n1 = a.size();
        int n2 = b.size();

        if (n1 > n2)
        {
            return FindMedian(b, a);
        }

        int total_size = n1 + n2;
        bool is_even = total_size % 2 == 0;
        int half = (total_size + 1) / 2;

        int left = 0, right = n1;

        while (left <= right)
        {
            int index_a = left + (right - left) / 2;
            int index_b = half - index_a;

            double a_left = index_a > 0 ? a[index_a - 1] : numeric_limits<double>::lowest();
            double a_right = index_a < n1 ? a[index_a] : numeric_limits<double>::max();
            double b_left = index_b > 0 ? b[index_b - 1] : numeric_limits<double>::lowest();
            double b_right = index_b < n2 ? b[index_b] : numeric_limits<double>::max();

            if (a_left <= b_right && b_left <= a_right)
            {
                if (is_even)
                {
                    return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
                }
                return max(a_left, b_left);
            }

            if (a_left > b_right)
            {
                right = index_a - 1;
            }
            else
            {
                left = index_a + 1;
            }
        }

        return -1; // Should never reach here
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        return FindMedian(nums1, nums2);
    }
};
