#include <string>
#include <vector>

using namespace std;

class Solution242
{
    std::vector<int> computeFrequencies(const string& s)
    {
        std::vector result(26, 0);
        for (const auto& v : s)
        {
            int i = v - 'a';
            result[i] += 1;
        }
        return result;
    }

public:
    bool isAnagram(string s, string t)
    {
        const auto sf = computeFrequencies(s);
        const auto st = computeFrequencies(t);
        for (int i = 0; i < sf.size(); ++i)
        {
            if (sf[i] != st[i])
            {
                return false;
            }
        }
        return true;
    }
};
