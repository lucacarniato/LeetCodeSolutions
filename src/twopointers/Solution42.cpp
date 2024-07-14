#include <vector>

using namespace std;

class Solution42
{
public:
    int trap(vector<int>& height)
    {
        int l = 0;
        int r = height.size() - 1;

        int maxl = height[l];
        int maxr = height[r];
        int result = 0;
        while (l < r)
        {
            if (maxl <= maxr)
            {
                result = std::max(height[l] - maxl, 0);
                l++;
                maxl = std::max(maxl, height[l]);
            }
            else
            {
                result = std::max(height[r] - maxr, 0);
                r--;
                maxr = std::max(maxr, height[r]);
            }
        }
        return result;
    }
};

class Solution42Second
{
public:
    int trap(vector<int>& height)
    {
        int result = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r)
        {
            // left
            int h = height[l];
            int v = 0;
            int p = l;
            while (l < r && height[l + 1] < h)
            {
                v += h - height[l + 1];
                l++;
            }
            if (l >= r && height[r] < h)
            {
                l = p;
            }
            else
            {
                result += v;
                l++;
            }

            // right
            h = height[r];
            v = 0;
            p = r;
            while (r > l && height[r - 1] < h)
            {
                v += h - height[r - 1];
                r--;
            }
            if (l >= r && height[l] < h)
            {
                r = p;
            }
            else
            {
                result += v;
                r--;
            }
        }

        return result;
    }
};
