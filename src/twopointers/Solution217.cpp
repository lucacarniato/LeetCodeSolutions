#include <set>
#include <vector>

using namespace std;

class Solution217
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        set<int> s;
        for (const auto& v : nums)
        {
            if (s.contains(v))
            {
                return true;
            }
            s.insert(v);
        }
        return false;
    }
};
